/*
입출력 : 3<=N,M<=8, 0빔1벽2바
		바<=10, 3<=빈
		최대 안전 영역의  크기
해석 :
	1. 벽 3개 세우기
	2. 바이러스 퍼트리기
	3. 안전영역 수 세기 
아이디어 : 벽세우기는 조합으로, 바이러스는 CC로, 안전영역 합하기
	1. 벽 3개 세우기
		2. for(모든 바이러스 위치) dfs()
		3. for(모든영역) if(v 안전영역, a 빈칸) cnt++
	4. 벽 수거 
시간복잡도 : 62C3 * (64+64) / 62*61*60*120/3 = 4천만 < 1억
자료구조 : N,M,ret,a[10][10],v[10][10], bius,zero 
조심 : ret 최대값, v초기화, 벽수거 
*/

#include<bits/stdc++.h>
using namespace std;
int N,M,ret, a[10][10], v[10][10], wall;
vector<pair<int,int>> bius, zero;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; 
int dfs(int y, int x, int cnt){
	// start
	v[y][x] = cnt;
	
	// re
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny>=0 && ny < N&&  nx>=0 && nx < M && a[ny][nx] == 0 && v[ny][nx] ==0){
			cnt = dfs(ny,nx,cnt+1); 
		} 
	} 
	
	//
	return cnt; 
} 

int go(){
	// init
	memset(v, 0, sizeof(v));
//	fill(&v[0][0], &v[0][0] + 10 * 10, 0);
	int cnt =0;
	
	// dfs
	for(auto b : bius){
		cnt = dfs(b.first, b.second, cnt+1); 
	} 
	
	// count 
	return N * M - wall -3 - cnt; 
} 

int main(){
	// input
	cin >> N>>M;
	for(int i=0; i< N; i++){
		for(int j=0; j<M; j++){
			cin >> a[i][j];
			switch(a[i][j]){
				case 2: bius.push_back({i,j});break;
				case 0: zero.push_back({i,j});break;
				case 1: wall++;break; 
			} 
		} 
	}
	
	// calc
	int NUM = zero.size(); 
	for(int i=0; i<NUM-2; i++){
		for(int j=i+1;j<NUM-1; j++){
			for(int k=j+1;k<NUM; k++){
				pair<int,int> t;
				t =  zero[i]; a[t.first][t.second] = 1; 
				t =  zero[j]; a[t.first][t.second] = 1;
				t =  zero[k]; a[t.first][t.second] = 1;
				
				ret = max(ret, go()); 
				
				t =  zero[i]; a[t.first][t.second] = 0; 
				t =  zero[j]; a[t.first][t.second] = 0;
				t =  zero[k]; a[t.first][t.second] = 0;
			} 
		} 
	} 
	
	// output
	cout << ret << "\n";
	return 0; 
} 
