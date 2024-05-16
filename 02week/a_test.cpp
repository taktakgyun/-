// n,m <=100 / 1,1-> n,m���� �̵��ϴ� �ּ� ĭ��
// idea : dfs /4���� Ž�� �ؼ� ���� ���� ��Ʈ Ž�� Ȯ�� ����/  
// -> 1. �ϴ� ������ �� �湮 ��Ű��(ī��Ʈ ���), ���ͼ� �湮����(0) 
// -> 2. 	ī���� �ϰ�, ���� ã�Ƽ� 2���� ���� ������� ����.
// -> 3.	���� /���� ���ų�(-1) / �����ߴٸ�, ī������ ��ȯ�Ѵ�. 
// �ð����⵵ : n*m*4 40_000 < 1��  
// �ڷᱸ�� : N,M map[n+2][m+2]  visited[n][m],  n,m ��ġ�� �̵�Ƚ�� ��� ,ret 
// ��谪 : �ʹ� OOI, ������ �������� ���ư��� ��, �ִ� ���߿� ���� ª�� �� 

#include<bits/stdc++.h>
using namespace std;
const int N=100, M=100; 
int n,m, mp[N+4][M+4], visited[N+4][M+4], ret=100000;

int dx[4] ={1,0,-1,0} ,dy[4] = {0,-1,0,1}; 
void dfs(int y, int x, int cnt){

	// end
	if (cnt >= ret) return; 
	if (y==n && x==m){
		ret = min(ret, visited[y][x]); 
		return; 
	}
	// re
	for (int i=0; i<4; i++){
		int ny = y + dy[i]; 
		int nx = x + dx[i];
		if (ny>0 && ny<=n && nx>0 && nx<=m){
			
			if(mp[ny][nx] == 1 && visited[ny][nx] == 0 ){// no visited 
				visited[ny][nx] = cnt+1;
				dfs(ny,nx,cnt+1); 
				visited[ny][nx] = 0;
			}
		} 
	} 
} 

int main(){
	// input
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){ 
		for(int j=1; j<=m; j++){
			scanf("%1d", &mp[i][j]); 
//			mp[i][j] = (temp[j-1]-'0'); 
		} 
	}
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=m; j++){
//			cout << mp[i][j] << " ";	
//		}	 
//		cout<<endl; 
//	} 
	// calc
	visited[1][1] = 1;
	dfs(1,1,1);
	
	// output
	cout << ret << "\n";  
} 
 
 
 

