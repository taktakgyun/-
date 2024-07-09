/*
����� : N<=��, M<=�ʸ�, �ŷڰ���*M 
		/ ���� ���� ��ŷ�� �� �ִ� ����� ���ʴ��
���̵�� : dp ó�� �̹� �������� ��ȯ�ϰ�, �ƴϸ� ���Ѵ�.
			�湮�� �ϳ� �������� üũ�ؾ��ҵ�
	1. dfs_cnt(com_num) 
		1. if �湮Ȯ��? ��ȯ �߰� return -1 
			else �湮 üũ  
		2. if v[com_num] �̹� �� ����? return �̹� ���Ѱ� ��ȯ 
		2. if �ŷ� ���� ��? return 1
		3. for(�ŷ� �ĵ� �ϳ��� ��ȸ) cnt += dfs_cnt(new_num)
		4. dp ������ return cnt
	2. ��ȯ�ϴ� ģ���� ���� ���� ����� �ֱ�?????
		�Ʒ� �ִ� ģ���� ���ؼ� �ִ����� ������Ʈ �ϱ�
	3. �����ϱ�		 
�ð����⵵ : N*M+M+NlogN �ʾ�+�ʸ�+�̽ʸ� < ���� / df�� ������ �������� ���� ��  
�ڷᱸ�� :  N, M, cnt[��], Faith[��], v[��], ret 
���� : �ŷڰ��谡 ��ȯ�� ���� �ֱ� ������ �湮ǥ�� �ʼ� 
		���� �ŷڰ����� ģ������ ��� �ұ�? ����
		v �ʱ�ȭ ���ֱ�, �湮Ȯ�� ���ϱ�
		dp ���� ���ϱ�  
��谪 : M�� ���������(1) 
		M�� �������(�ʸ�)
		N�� �������(1)
		N�� ���� ���(10��)
		�Ѵ� ���� ���
		�Ѵ� ���� ���
		N�� ���� M�� ��û ���� ���
		���� �ŷڰ��踦 �����ϰ� �ִ� ģ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int N,M, cnt[10001], v[10001];
vector<int> Faith[10001], ret;
 
int dfs_cnt(int num){
	// end
	v[num] = 1; // �湮 üũ
	if(cnt[num] > 0) return cnt[num];
	
	// re
	int ret=1; // ���� ����  
	for(int new_num : Faith[num]){
		if(v[new_num] == 0) ret += dfs_cnt(new_num); 
	}
	
	// end 
	cnt[num] = ret;
	return ret; 
}
int dfs_max(int num){
	// start 
	v[num] = 1; // �湮 üũ
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

 
