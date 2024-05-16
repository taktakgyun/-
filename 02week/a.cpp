// n,m <=100 / 1,1-> n,m���� �̵��ϴ� �ּ� ĭ��
// idea : bfs /4���� Ž�� �ؼ� ���� ���� ��Ʈ Ž�� Ȯ��(�Ȱ���) ����/  
// -> 1. �ϴ� ������ �� �湮 ��Ű��(ī��Ʈ ���), ť�� ���  
// -> 2. 	���� ã�Ƽ� 2���� ���� ������� ����.
// -> 3. n,m�� ��ϵ� �� �� Ȯ�� 
// �ð����⵵ : n*m*4 40_000 < 1��  
// �ڷᱸ�� : N,M map[n+2][m+2]  visited[n][m] , ť,  
// ��谪 : �Է��� �پ�����, �ʹ� OOI, ������ �������� ���ư��� ��, �ִ� ���߿� ���� ª�� �� 

#include<bits/stdc++.h>
using namespace std;
const int N=100, M=100; 
int n,m, mp[N+4][M+4], visited[N+4][M+4], ret=100000, x,y;
queue<pair<int,int>> qe; 
int dx[4] ={1,0,-1,0} ,dy[4] = {0,-1,0,1}; 
int main(){
	// input
	scanf("%d %d\n", &n, &m);
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%1d", &mp[i][j]); 
		} 
	} 
	
	// calc
	visited[1][1] = 1;
	qe.push({1,1});
	
	while(qe.size()){
		tie(y,x) = qe.front(); qe.pop(); 
		for(int d=0; d<4; d++){
			int nx = x+dx[d];
			int ny = y+dy[d];
			if(ny>0 && ny<=n &&  nx>0 && nx<=m && mp[ny][nx]==1 && visited[ny][nx]==0){
				visited[ny][nx] = visited[y][x]+1;
				qe.push({ny, nx}); 
			}
		} 
	} 
	
	// output
	printf("%d", visited[n][m]); 
} 
 

