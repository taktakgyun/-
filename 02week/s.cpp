/*
입출력 : N<=만, M<=십만, 신뢰관계*M 
		/ 가장 많이 해킹할 수 있는 놈부터 차례대로
아이디어 : dp 처럼 이미 구했으면 반환하고, 아니면 구한다.
			방문을 하나 돌때마다 체크해야할듯
	1. dfs_cnt(com_num) 
		1. if 방문확인? 순환 추가 return -1 
			else 방문 체크  
		2. if v[com_num] 이미 값 세팅? return 이미 구한거 반환 
		2. if 신뢰 없는 컴? return 1
		3. for(신뢰 컴들 하나씩 조회) cnt += dfs_cnt(new_num)
		4. dp 세팅후 return cnt
	2. 순환하는 친구들 개수 같게 만들어 주기?????
		아래 있는 친구와 비교해서 최댓값으로 업데이트 하기
	3. 정렬하기		 
시간복잡도 : N*M+M+NlogN 십억+십만+이십만 < 오억 / df라 연산이 빡세지는 않을 듯  
자료구조 :  N, M, cnt[만], Faith[만], v[만], ret 
조심 : 신뢰관계가 순환할 수도 있기 때문에 방문표시 필수 
		서로 신뢰관계인 친구들은 어떻게 할까? 허허
		v 초기화 해주기, 방문확인 꼭하기
		dp 세팅 꼭하기  
경계값 : M이 적어은경우(1) 
		M이 많은경우(십만)
		N이 적은경우(1)
		N이 만은 경우(10만)
		둘다 많은 경우
		둘다 적은 경우
		N에 비해 M이 엄청 많은 경우
		서로 신뢰관계를 구축하고 있는 친구들 
*/
#include<bits/stdc++.h>
using namespace std;
int N,M, cnt[10001], v[10001];
vector<int> Faith[10001], ret;
 
int dfs_cnt(int num){
	// end
	v[num] = 1; // 방문 체크
	if(cnt[num] > 0) return cnt[num];
	
	// re
	int ret=1; // 본인 포함  
	for(int new_num : Faith[num]){
		if(v[new_num] == 0) ret += dfs_cnt(new_num); 
	}
	
	// end 
	cnt[num] = ret;
	return ret; 
}
int dfs_max(int num){
	// start 
	v[num] = 1; // 방문 체크
	if(Faith[num].empty()) return cnt[num]; 
	
	// re 
	for(int i : Faith[num]){
		int temp =  0; 
		
		if(v[i] == 0) temp = dfs_max(i); 
		else temp = cnt[i];
		 
		cnt[num] = max(cnt[num], temp); 
	}
	return cnt[num]; 
} 

int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL);
	
	cin >> N >> M;
	while(M--){
		int a,b;
		cin >> a >> b;
		Faith[b].push_back(a); 
	}
	
	// calc
	int max_v = -1000;
	for(int i=1; i<=N; i++){ 
		// init
		memset(v, 0, sizeof(v));
//		fill(v, v+(N+1), 0); 
		
		// dfs
		max_v = max(max_v, dfs_cnt(i)); 
	}
	
	// update 
	memset(v, 0, sizeof(v)); 
//	fill(v, v+(N+1), 0);
	for(int num=1; num<=N; num++){
		if(v[num] == 0) dfs_max(num);
	}
	
	// output
	for(int num=1; num<=N; num++){
		if(cnt[num] - max_v >= 0) cout << num << " "; 
	} 
	cout << "\n";
	
	return 0; 
} 

 
