/*
입출력 : 3<= N,M <= 8 / 빈칸은 3이상, 2<=바이러스<=10 /안전구역개수 
		/ 추가벽 3개 
해석 : 전파 시뮬레이션(dfs 커넥티드컴포넌트), 개수가 최대가 되는 찾아라.
아이디어 : 
 
 아이디어 : 그냥 조합으로 계산
 	1. 조합으로 벽을 3개 세운다.
	 	2. for(모든지역) if(안방문한 지역(0인))  dfs
	3. 벽 수거, visited 초기화
	
	dfs. 0인거 전파해서 개수 구하기, 근데, 바이러스를 만나면 -1반환 
시간 복잡도: 62C3 * 64 /  64*62*61*60 / 16만 <2억? 가능할지도? 
자료구조 : N,M, a[10][10], v[10][10], cnt, ret; 
조심 : v 초기화 ret 최대값(초기 세팅) 
경계값 : 안전구역 3개만 있을 때,
*/

#include<bits/stdc++.h>
using namespace std;
int N, M, ret, a[10][10], v[10][10];

void print_v(){
	string amap, vmap;
	 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			amap += to_string(a[i][j]) + " "; 
			vmap += to_string(v[i][j]) + " ";
		}
		amap += "\n"; 
		vmap += "\n";
	}
	cout << amap << vmap<<"\n"; 
} 

int dx[4]={0,1,0,-1} , dy[4]={1,0,-1,0} ; 
int dfs(int y, int x, int flag){
	// start
	v[y][x] = flag;
	// re
	for (int i=0; i<4; i++){
		int nx = x+dx[i]; 
		int ny = y+dy[i];
		if(nx>=0 && nx<M &&  ny>=0 && ny<N && v[ny][nx] == 0 ){
			if(a[ny][nx] == 1) v[ny][nx] = -2;
			
			else if(a[ny][nx] == 2 || flag <= 0){
				flag = dfs(ny, nx, -1);
			} 
			else if(a[ny][nx] == 0) flag = dfs(ny, nx, flag+1); 
			
		} 
	}
	 
	// output
	return flag; 
}

int go(){
	// init
	int cnt=0; 
	memset(v, 0, sizeof(v)); 
	
	// find 
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(a[i][j]==0 && v[i][j]==0){ 
				cnt = max( dfs(i,j,cnt+1), cnt);
			}
		}
	}
	return cnt; 
} 

int main(){
	// input
	cin >> N >> M;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) cin >> a[i][j]; 
	}
	
	// cala
	int ms = N*M; 
	for(int i=0; i<ms-2; i++){
		if(a[i/M][i%M] != 0) continue;
		a[i/M][i%M] = 1; 
		for(int j=i+1; j<ms-1; j++){
			if(a[j/M][j%M] != 0) continue;
			a[j/M][j%M] = 1; 
			for(int k=j+1; k<ms; k++){
				if(a[k/M][k%M] != 0) continue;
				a[k/M][k%M] = 1; 
				
				ret = max(ret, go()); 
				 
				a[k/M][k%M] = 0; 
			}
			a[j/M][j%M] = 0;
		} 
		a[i/M][i%M] = 0;
	}
	
	// output
	cout << ret << "\n";
	return 0; 
} 
