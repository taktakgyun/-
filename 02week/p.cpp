/*
입출력 : 3<= N,M <= 8 / 0빈,1벽, 2바  
		/ 빈칸은 3이상, 2<=바이러스<=10 /안전구역개수 
		/ 추가벽 3개 
해석 : 전파 시뮬레이션(dfs 커넥티드컴포넌트), 개수가 최대가 되는 찾아라.
아이디어 : 추가벽 3개는 조합으로 찾고, 
			전파는 dfs를 통해 빈칸 CC를 찾자
			바이러스가 나오면 범위 밖 값을 내보내자
	1. 조합으로 추가벽 3개를 세운다.
		2. for(모든 맵 확인) 
			3. if(방문했고 거나 벽이라면) continue 
			4. if(바이러스라면) dfs(y,x,-1)
			5. else ret = max( dfs(y,x,1), ret) 
		6. 벽 회수
dfs 경우의 수 :
	1. 벽인 경우-종료 / 바이러스-(-1)전파, cnt 없음 / 빈칸 - cnt 전파, cnt 카운팅 
	2. 빈칸으로 가다가 바이러스 만남(이전에 값 확인) - 이전 cnt는 의미 없고, -1 반환
	우선순위 : 벽 만남, 바이러스 전파, 일반전파  
시간복잡도 : 62C3 * 4 * 64 / 64*62*61*60*4 / 80만 < 2억
자료구조 : N,M, a[10][10], v[10][10], ret, cnt
조심 : 벽회수, v초기화, cnt 초기화, ret최댓값 유지 -1 조심,
		dfs에서 바이러스 경우 조심, 벽에 닿는 경우 조심  
경계값 :  모서리에 바이러스 하나씩, 띄모서리에 하나씩 
*/
#include<bits/stdc++.h>
using namespace std;
 
int N,M,ret,a[10][10], v[10][10];

#define ROW(a) a/M 
#define COL(a) a%M

int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};

int dfs(int y, int x, int cnt){
	// start
	v[y][x] = cnt;

	// re
	for(int d=0; d<4; d++){
		int ny = y + dy[d]; 
		int nx = x + dx[d];
		if(ny>=0 && ny <N && nx>=0 && nx < M && v[ny][nx] == 0){
			if (a[ny][nx] == 1) //wall 
				v[ny][nx] = -1000;
			
			else if ( a[ny][nx]==2 || cnt==-1 ) //바이러스 
				cnt = dfs(ny,nx,-1);
			
			else cnt = dfs(ny,nx,cnt+1); //일반시작  
		} 
	} 
	
	return cnt; 
} 
int go(){
	// init
	int cnt = 0; 
	memset(v, 0, sizeof(v));
	
	// logic
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(v[i][j] == 0){
//				if(a[i][j] == 1) v[i][j] = -1000;
//				else if(a[i][j] == 2) dfs(i,j,-1);
//				else if(a[i][j] == 0)cnt = max(dfs(i,j,cnt+1), cnt);
				switch(a[i][j]){ 
					case 0 : cnt = max(dfs(i,j,cnt+1), cnt);
					case 1 : v[i][j] = -1000; break; // 벽 
					case 2 : dfs(i,j,-1); break; // 바이러스
				}
			}
		} 
	} 
	//
	return cnt; 
} 
int main(){
	// input
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> a[i][j]; 
		} 
	} 
	
	// calc
	int NUM = N*M;
	for(int i=0; i<NUM-2; i++){
		if( a[ROW(i)][COL(i)] != 0) continue; 
		a[ROW(i)][COL(i)] = 1; 
		for(int j=i+1; j<NUM-1; j++){
			if( a[ROW(j)][COL(j)] != 0) continue;
			a[ROW(j)][COL(j)] = 1; 
			for(int k=j+1; k<NUM; k++){
				if( a[ROW(k)][COL(k)] != 0) continue;
				a[ROW(k)][COL(k)] = 1; 
				

				ret = max(ret, go()); 

				a[ROW(k)][COL(k)] = 0; 
			} 
			a[ROW(j)][COL(j)] = 0; 
		} 
		a[ROW(i)][COL(i)] = 0;
	}
	
	// output
	cout << ret << "\n";
	return 0; 
} 

