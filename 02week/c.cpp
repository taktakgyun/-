// N<=100 a[n][n] h<=100 //안전지역의 개수를 구해라
// 높이를 높여가며 안전지역을 구해야한다. 
// idea: 높이 마다 안전지역을 전파 시킨다. dfs 
// -> 0. 최대, 최소 높이를 구해놓는다. 
// -> 1. 초기화 for min_v <= h <= max_v 
//			cnt  
// 			for 맵 모두 순회>
//				if(안전가능안 안방문 지역)  dfs(기준h) 고고
//			안전지역 개수 업데이트 
// 시간복잡도: h(max-min)* N*N* ??? / 100*100*100  천만...< 
// 자료구조 : N,H a[100][100], cnt, ret, v[100][100]
// 경계값 : v와 cnt는 초기화 할것, ret은 최소값 지정
//		-> OOI 점검, 높이가 100 인거, 다 같은 높이,  
// 시간예측 30분
#include<bits/stdc++.h>
using namespace std;
int N,H, cnt, ret=-100000, a[101][101],v[101][101];

int dx[4] = {1,0,-1,0}, dy[4] = {0,-1,0,1}; 
void dfs(int y, int x, int h,int flag){
	// start
	v[y][x] = flag; 
	
	// re
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx>=0 && nx<N &&  ny>=0 && ny<N && a[ny][nx] >= H && v[ny][nx] == 0)
			dfs(ny,nx,h,flag); 
		
	} 
} 

int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	int min_v=100, max_v=1; 
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> a[i][j];
			min_v = min(min_v, a[i][j]);
			max_v = max(max_v, a[i][j]);
		} 
	}
	
	// calc
	max_v = min(max_v, 100); // 100 안넘도록 조정  
	for(H=min_v; H<=max_v; H++){
		// init
		cnt = 0;
		memset(v, 0, sizeof(v)); 
		
		// calc
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				//안전위치 전파 
				if(a[i][j] >= H && v[i][j] == 0) dfs(i,j,H,++cnt); 
			}
		}
		ret = max(ret, cnt); 
	} 
	
	// output
	cout << ret << "\n"; 
	 
} 
 
