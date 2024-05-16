// n,m <=100 / 1,1-> n,m으로 이동하는 최소 칸수
// idea : bfs /4방향 탐색 해서 가장 적은 루트 탐색 확인(안간곳) 고고고/  
// -> 1. 일단 가려는 곳 방문 시키고(카운트 기록), 큐에 기록  
// -> 2. 	갈곳 찾아서 2번과 같은 방법으로 간다.
// -> 3. n,m에 기록된 곳 값 확인 
// 시간복잡도 : n*m*4 40_000 < 1억  
// 자료구조 : N,M map[n+2][m+2]  visited[n][m] , 큐,  
// 경계값 : 입력이 붙어있음, 맵밖 OOI, 이전에 간곳으로 돌아가는 것, 있는 것중에 가장 짧은 곳 

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
 

