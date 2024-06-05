/*
����� : T??, N<=õ,K<=�ʸ�, 0=<Dn<=�ʸ� / x->y���� w��ǥ
		/ �ּ� �Ǽ� �ð�
�ؼ� : 1. �� ������ �����Ǿ�� �ǹ��� ���� �� �ִ�.
		2. �������� 1�� �̻��̴�.
		3. �ǹ��� ���ÿ� ������ �ִ�.
�м� : 
	������ ���� �׷����� ǥ��,
	dfs�� ����ؼ� �ð��� ���Ѵ�. / weight�� ���� 
	dp�� ����ؼ� �ϼ� �Ǿ�����, �����Ѵ�.
���̵�� : 
	�ڱ� . �ð��� �����ϰ�, ������ y�������� ���� �׷����� �����Ѵ�.
	1. dfs(w)
		if(�̹� ���� ������) ��ȯ
		if(grif[w].empty) �ð� �ٷ� ��ȯ
		//re
		for(w�� ����� ��� �͵�) ret = max(dfs, ret)
		return ret+D[w] 
	2.
�ð����⵵ : T*(N+K+) 
�ڷᱸ�� : T, N, K, D[õ+1], a[õ+2] weight[õ+1 
���� : 
	�ּ� �Ǽ��ð��� 0�̶� ret ����, 
	���� D, W, a, weight �ʱ�ȭ  \
	D�� �ſ�ū ��� ��
��谪 : D�� �ſ�ŭ long long ����, 
		K�� ��û ���� ���,  
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
 

