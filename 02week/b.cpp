// T . M,N<=50 k<2500
// idea : dfs를 통해 그래프 컴포넌트 그룹에 전파  
// -> 1. 50*50에 배추 위치를 보고, 없으면 근처로 방문시킨다.
// -> 2. 다 방문시키면, 안 방문한 배추를 찾아가서 전파한다.(1번 반복) 
// 시간 복잡도 : 따로 신경 쓸것은 없는 듯? N*M 만큼 들듯?
// 자료구조 : T,N,M,K, m[50][50] v[50][50], cnt, ret 
// 경계값 : OOI 조심, k개수 많으므로 입출력 최적화 ,
// 	->  테케가 있으므로 배추와 방문을 초기화 해줘야함, cnt 초기화

#include <bits/stdc++.h>
using namespace std;
const int n=50, m=50;
int T,N,M,K, mp[n+4][m+4], v[n+4][m+4], cnt;
string ret;

int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0}; 
void dfs(int y, int x, int flag){
	// end
	//?? 
	// re
	for(int i=0; i<4; i++){
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		if( ny>=0 && ny<N && nx>=0 && nx < M && mp[ny][nx] == 1 && v[ny][nx] == 0 ){
			v[ny][nx] = 1;
			dfs(ny, nx, flag); 
		} 
	} 
} 

int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while(T--){
		// init
		cnt =0;
		memset(mp, 0, sizeof(mp)); 
		memset(v, 0, sizeof(v)); 
		
		//input
		cin >> N >> M >> K; 
		for(int i=0; i<K; i++){
			int x,y; 
			cin >> y >> x; 
			mp[y][x] = 1; 
		} 
		// calc 
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				 if(mp[i][j] == 1 && v[i][j] == 0){
				 	cnt++;
					dfs(i,j,cnt); 
				 } 
			} 
		}
		
		// output
		ret += to_string(cnt) + "\n"; 
	} 
	
	// output
	cout << ret; 
} 
 
