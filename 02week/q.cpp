/*
입출력 : H,W<=100 , 0(X), 1(치즈)  / 치즈 모두 녹음, 1시간전
해석 :
	1. 치즈의 표면을 찾는다.
	2. 치즈 표면을 없앤다.
	3. 몇시간이 지나야 치즈가 다 녹는지 구한다. 
	extra. 구멍이 난 치즈는 어떻하지? 
분석 : 
	- 공기중 커넥티드 컴포넌트를 구한다.(가장자리부분만)
	- 안 녹는 치즈 CC를 구한다.(주변이 공기중 이지 않은 것)
	- 시간을 카운팅하고 녹은 친구로 초기화 한다.
아이디어 : 공기중 CC와 안 녹은 치즈 CC를 구한다! 
	- 무한 반복 / 나중에 안녹은 치즈 없으면 종료
		- 공기중 CC 구하기
		- 안 녹은 CC 구하기
		- 안 녹은 치즈 개수 구하기 / 시간++ 
		- if(안녹은 치즈 없으면 ) 종료
		- else 현재 상태 안녹은 치즈로 초기화 하기
시간 복잡도 : (N/2)=AA  / AA*(4*N+N*N)  / 50*(400+만) = 50만 < 1억 
자구 : H,W, A[102][102], Air[102][102], Chz[102][102],T  
조심 : 공기중 CC, 안 녹은 치즈 CC 초기화 잘 할것, 치즈1번부터 하기  
경계 : 모두 치즈도 도배, 치즈 하나도 없음  
*/
#include<bits/stdc++.h>
using namespace std;
int H,W, A[111][111], Air[111][111], Chz[111][111], T, before_chz;  

int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1}; 

void print_arr(int (*arr)[111]){
	string ret; 
	for(int i=0; i<=H+1; i++){
		for(int j=0; j<=W+1; j++){
			ret += to_string(arr[i][j]) + " "; 
		} 
		ret += "\n"; 
	}
	cout<<ret<<"\n"; 
} 

int dfs_chz(int y, int x, int cnt){
	// start
	for(int i=0; i<4; i++){ // 주변이 공기 인지 판별 
		int ny = y+dy[i];
		int nx = x+dx[i];
		// 주변이 하나라도 공기면 숙청  
		if(ny>=0 && ny<=H+1 && nx>=0 && nx<=W+1){
			if(Air[ny][nx] > 0) return -1; 
		} 
	}
	Chz[y][x] = cnt;
	
	// re 
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny>0 && ny<=H && nx>0 && nx<=W){
			if(Chz[ny][nx] == 0 && A[ny][nx] != 0)
				cnt = max(dfs_chz(ny,nx,cnt+1), cnt); 
		} 
	}
	return cnt; 
} 

int dfs_air(int y, int x, int cnt){
	// start
	Air[y][x] = cnt;
	
	// re
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny>=0 && ny<=H+1 && nx>=0 && nx<=W+1){
			if(Air[ny][nx] == 0 && A[ny][nx] == 0)
				cnt = dfs_air(ny,nx,cnt+1); 
		} 
	}
	return cnt; 
} 

int main(){
	// input
//	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W;
	
	for(int i=1; i<=H; i++){
		for(int j=1; j<=W; j++){
			cin >> A[i][j];
			if(A[i][j] == 1) before_chz++; 
		} 
	}
	
	// calc
	while(1){
		// init
		memset(Air, 0, sizeof(Air));
		memset(Chz, 0, sizeof(Chz));
		// set Air
		dfs_air(0,0,1);
//cout<<T<<":Air\n";print_arr(Air); 
		int chz_cnt = 0; 
		// set Chz
//cout<<T<<":A\n";print_arr(A);
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				if(Chz[i][j] == 0 && A[i][j] > 0) 
					chz_cnt = max(dfs_chz(i,j,chz_cnt+1), chz_cnt); 
			} 
		}
		T++;
		
//cout<<T<<":Chz\n";print_arr(Chz); 
		// check
		if(chz_cnt > 0){// init 
 			before_chz = chz_cnt; 
			for(int i=1; i<=H; i++){
				for(int j=1; j<=W; j++){
					if(Chz[i][j] > 0) A[i][j] = 1;
					else A[i][j] = 0;
				} 
			}	
		} 
		// output
		else{
			if(before_chz > 0) cout << T<<"\n"<<before_chz<<"\n";
			else cout << 0 <<"\n"<<before_chz<<"\n";
				
			break; 
		}
		
	} 
	
	return 0; 
} 
