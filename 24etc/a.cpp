/*
입출력 : T??, N<=천,K<=십만, 0=<Dn<=십만 / x->y조건 w목표
		/ 최소 건설 시간
해석 : 1. 선 조건이 만족되어야 건물을 지을 수 있다.
		2. 선조건은 1개 이상이다.
		3. 건물을 동시에 지을수 있다.
분석 : 
	조건을 방향 그래프로 표현,
	dfs를 사용해서 시간을 구한다. / weight가 있음 
	dp를 사용해서 완성 되었으면, 저장한다.
아이디어 : 
	자구 . 시간을 저장하고, 순서를 y기준으로 방향 그래프를 형성한다.
	1. dfs(w)
		if(이미 세팅 됐으면) 반환
		if(grif[w].empty) 시간 바로 반환
		//re
		for(w와 연결된 모든 것들) ret = max(dfs, ret)
		return ret+D[w] 
	2.
시간복잡도 : T*(N+K+) 
자료구조 : T, N, K, D[천+1], a[천+2] weight[천+1 
조심 : 
	최소 건설시간이 0이라 ret 조심, 
	테케 D, W, a, weight 초기화  \
	D가 매우큰 경우 조
경계값 : D가 매우큼 long long 가자, 
		K가 엄청 많은 경우,  
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int T,N,K, D[1004], X, Y, t; 
ll weight[1004], W;
vector<int> g[1004];
string ret; 

ll dfs(int seq){
	// end
	if( g[seq].empty() ) weight[seq] = D[seq]; 
	if(weight[seq] >= 0) return  weight[seq];
	ll w=0; 
	// re
	for(int n_seq : g[seq]){
		w = max(dfs(n_seq), w); 
	}
	
	// dp 
	weight[seq] = w + D[seq]; 
	return weight[seq]; 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	// input 
	cin >> T;
	while(T--){ 
		// input 
		cin >> N >> K; 
		
		// init
		for(int i=1; i<=1000; i++){
			g[i].clear();
			weight[i]=-1; 
		}
		
		// input 
		for(int i=1; i<=N; i++){
			cin >> D[i]; 
		} 
		
		for(int i=1; i<=K; i++){
			cin >> X >> Y;
		 	g[Y].push_back(X);
		}
		cin >> W;
		
		// calc and output 
		ret += to_string(dfs(W))+"\n"; 
	}
	// output
	cout << ret;
	return 0; 
} 
 

