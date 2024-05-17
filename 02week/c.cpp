// N<=100 a[n][n] h<=100 //���������� ������ ���ض�
// ���̸� �������� ���������� ���ؾ��Ѵ�. 
// idea: ���� ���� ���������� ���� ��Ų��. dfs 
// -> 0. �ִ�, �ּ� ���̸� ���س��´�. 
// -> 1. �ʱ�ȭ for min_v <= h <= max_v 
//			cnt  
// 			for �� ��� ��ȸ>
//				if(�������ɾ� �ȹ湮 ����)  dfs(����h) ���
//			�������� ���� ������Ʈ 
// �ð����⵵: h(max-min)* N*N* ??? / 100*100*100  õ��...< 
// �ڷᱸ�� : N,H a[100][100], cnt, ret, v[100][100]
// ��谪 : v�� cnt�� �ʱ�ȭ �Ұ�, ret�� �ּҰ� ����
//		-> OOI ����, ���̰� 100 �ΰ�, �� ���� ����,  
// �ð����� 30��
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
	max_v = min(max_v, 100); // 100 �ȳѵ��� ����  
	for(H=min_v; H<=max_v; H++){
		// init
		cnt = 0;
		memset(v, 0, sizeof(v)); 
		
		// calc
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				//������ġ ���� 
				if(a[i][j] >= H && v[i][j] == 0) dfs(i,j,H,++cnt); 
			}
		}
		ret = max(ret, cnt); 
	} 
	
	// output
	cout << ret << "\n"; 
	 
} 
 
