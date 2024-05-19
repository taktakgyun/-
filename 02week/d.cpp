// NMK <= 100 0<x1y1,x2y2<=NM 주어짐 - 분리된 영역의 개수와 각 넓이 
// idea : 커넥티드 컴포넌트 / 밖 사각형을 전파한다. dfs로 진행 
// 1. 사각형의 영역을 표시한 맵을 만든다.
// 2. for 모든 영역 : if 안방문한 밖사각형
//		3.  cnt++, 방문한 최대 개수 반환하
// 시간복잡도 : N*M*5  / 5만 < 1억
// 자료구조 : N,M,K a[100][100] v[100][100] cnt, length(vecter) 
// 경계값 : 넓이를 카운팅 해야한다. / 중간에 끊어졌을 때 합산이 되도록 한다.
//  OOI, 칸이라는 점을 유의한다(좌표를 칸으로 변경).
// cnt 1인 경우(모든 것이 연결됨, 일부만 남음) / 

#include<bits/stdc++.h>
using namespace std;
int N,M,K, a[104][104], v[104][104];
vector<int> ret;

int dx[4]={1,0,-1,0} , dy[4]={0,-1,0,1} ; 
int dfs(int y, int x, int cnt){
	// start
	v[y][x] = cnt+1;
	int ret =1; 
	
	// re 
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny>=0 && ny<M && nx>=0 && nx<N && a[ny][nx] == 0 && v[ny][nx] == 0){
			ret += dfs(ny,nx,cnt+ret); 
		} 
	}
	return ret; 
} 

int main(){
	// input 
	cin >> M >> N >>K;
	
	while(K--){
		int x1,y1,x2,y2;
		cin >>  x1>>y1>>x2>>y2;
		for(int i=y1; i<y2; i++){
			for(int j=x1; j<x2; j++)	a[i][j] = 1; 
		} 
	}
	
	// calc
	for(int y=0; y<M; y++){
		for(int x=0; x<N; x++){
			if(a[y][x] == 0 && v[y][x] == 0){
				ret.push_back(dfs(y,x,0));
			} 
		} 
	}  
	
	sort(ret.begin(),ret.end());  
	// output
	cout << ret.size()<<"\n";
	for(int i : ret) cout << i << " ";
	cout << "\n"; 
	
	
//	for(int y=M-1; y>=0; y--){
//		for(int x=0; x<N; x++){
//			printf("%2d ", v[y][x]); 
//			}
//			cout<<"\n"; 
//	}  
} 
