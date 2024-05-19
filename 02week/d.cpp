// NMK <= 100 0<x1y1,x2y2<=NM �־��� - �и��� ������ ������ �� ���� 
// idea : Ŀ��Ƽ�� ������Ʈ / �� �簢���� �����Ѵ�. dfs�� ���� 
// 1. �簢���� ������ ǥ���� ���� �����.
// 2. for ��� ���� : if �ȹ湮�� �ۻ簢��
//		3.  cnt++, �湮�� �ִ� ���� ��ȯ��
// �ð����⵵ : N*M*5  / 5�� < 1��
// �ڷᱸ�� : N,M,K a[100][100] v[100][100] cnt, length(vecter) 
// ��谪 : ���̸� ī���� �ؾ��Ѵ�. / �߰��� �������� �� �ջ��� �ǵ��� �Ѵ�.
//  OOI, ĭ�̶�� ���� �����Ѵ�(��ǥ�� ĭ���� ����).
// cnt 1�� ���(��� ���� �����, �Ϻθ� ����) / 

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
