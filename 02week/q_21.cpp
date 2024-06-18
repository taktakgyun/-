/*
입출력 : H, W <=100, 가장자리는 공기, 0공기 1 치즈
		모두녹을때 까지 시간, 그 바로전 녹은 개수
아이디어 : 공기중을 CC 하고, 치즈가 나오면 표면임
	1. 0,0을 기준으로 dfs 해서 CC구함
	2. 녹은 치즈 개수 구하고, 치즈 녹임
	3. if 남은 치즈 확인 / T , 이전 치즈 출력 
	3. else 계속 진행 / T++,  
	4.  
시간복잡도 : 50 * (N*N) 
자료구조 : H,W,A,V,dxdy, Chz,T, cnt 
경계값 : 
	- 아무것도 없을때,
	- 하나만 있을 때
	- 꽉찼때, 
*/
#include<bits/stdc++.h>
using namespace std;
int H,W, A[104][104], V[104][104], T,cnt;
int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
vector<pair<int,int>> Chz;

void dfs(int y, int x){
	// start
	V[y][x] = 1;
	
	// end
	if(A[y][x] == 1){
		Chz.push_back({y,x}); 
		return; 
	}
	
	// re
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny>=0 && ny<H &&  nx>=0 && nx<W){
			if(V[ny][nx]==0) dfs(ny,nx); 
		} 
	}
	return; 
}

bool check_chz(){
	for(int i=0; i<H; i++){
		for( int j=0; j<W; j++){
			if(A[i][j]==1) return true; 
		} 
	}
	return false; 
} 

int main(){
	// input
	cin >> H >> W;
	for(int i=0; i<H; i++){
		for( int j=0; j<W; j++){
			cin >> A[i][j]; 
		} 
	} 
	// calc
	while(1){
		// init
		memset(V, 0, sizeof(V));
		Chz.clear(); 
		
		// set 커넥티트 컴포넌트
		dfs(0,0);
		
		// 치즈 녹이기 
		cnt = Chz.size();
		for(auto a : Chz){
			A[a.first][a.second] = 0; 
		}
		T++;
		// 다 녹았으 면
		if(!check_chz()) break;
	} 
	// output 
	if( cnt == 0 ) cout << "0\n0\n";
	else cout << T << "\n"<<cnt<<"\n";
	
	return 0; 
} 
