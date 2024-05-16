// n,m <=100 / 1,1-> n,m으로 이동하는 최소 칸수
// idea : dfs /4방향 탐색 해서 가장 적은 루트 탐색 확인 고고고/  
// -> 1. 일단 가려는 곳 방문 시키고(카운트 기록), 나와서 방문해제(0) 
// -> 2. 	카운팅 하고, 갈곳 찾아서 2번과 같은 방법으로 간다.
// -> 3.	종료 /갈수 없거나(-1) / 도착했다면, 카운팅을 반환한다. 
// 시간복잡도 : n*m*4 40_000 < 1억  
// 자료구조 : N,M map[n+2][m+2]  visited[n][m],  n,m 위치에 이동횟수 기록 ,ret 
// 경계값 : 맵밖 OOI, 이전에 간곳으로 돌아가는 것, 있는 것중에 가장 짧은 곳 

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
 
 
 

