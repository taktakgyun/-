/* H<=100, W<=100, 안뜬 곳은 -1, 뜬 곳은 0이상 / 몇분 뒤 오는지 구하기 
기본 : 동쪽으로 이동 dx=1 dy=0
idea : dfs 동쪽으로만 이동시키기, 단 구름이 있으면 스탑/ 무조건 동쪽부터 확인  
- dfs : 끝이나 구름을 만날때까지 전파  
- 1. for(동쪽부터 모든 구간 참조)
- 2. 	if(클라우드인경우만 하기) dfs
시간복잡도 : nw * w     백만 < 1억
자료구조 : H, W, i,j, a[100][100],v[100][100],  
조심 : v는 -1로 초기화  
경계값 : 구름이 없어나 전부인경우,
		구름이 다 동쪽 벽에 있는경우,
		구름이 서쪽 벽에 있는경우
		hw가 1인경우, 100,100인경우 
*/
#include<bits/stdc++.h>
using namespace std;
int H,W,v[104][104];
const int dx=1;

void dfs(int y, int x, int flag){
	// re
	int nx = x + dx;
	if( nx < W && v[y][nx] == -1 ){
		v[y][nx] = flag;
		dfs(y,nx, flag+1); 
	} 
} 
int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> H >> W;
	
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			char t;
			cin >> t;
			if(t=='c') {
				v[i][j] = 0;
			} 
			else {
				v[i][j] = -1;
			} 
		}
	}
	
	// calc
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(	v[i][j] == 0) dfs(i,j,1); 
		}
	}
	
	// output 
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			cout << v[i][j] << " "; 
		}
		cout << "\n";	
	} 
} 

