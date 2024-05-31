/*
����� : 3<= N,M <= 8 / 0��,1��, 2��  
		/ ��ĭ�� 3�̻�, 2<=���̷���<=10 /������������ 
		/ �߰��� 3�� 
�ؼ� : ���� �ùķ��̼�(dfs Ŀ��Ƽ��������Ʈ), ������ �ִ밡 �Ǵ� ã�ƶ�.
���̵�� : �߰��� 3���� �������� ã��, 
			���Ĵ� dfs�� ���� ��ĭ CC�� ã��
			���̷����� ������ ���� �� ���� ��������
	1. �������� �߰��� 3���� �����.
		2. for(��� �� Ȯ��) 
			3. if(�湮�߰� �ų� ���̶��) continue 
			4. if(���̷������) dfs(y,x,-1)
			5. else ret = max( dfs(y,x,1), ret) 
		6. �� ȸ��
dfs ����� �� :
	1. ���� ���-���� / ���̷���-(-1)����, cnt ���� / ��ĭ - cnt ����, cnt ī���� 
	2. ��ĭ���� ���ٰ� ���̷��� ����(������ �� Ȯ��) - ���� cnt�� �ǹ� ����, -1 ��ȯ
	�켱���� : �� ����, ���̷��� ����, �Ϲ�����  
�ð����⵵ : 62C3 * 4 * 64 / 64*62*61*60*4 / 80�� < 2��
�ڷᱸ�� : N,M, a[10][10], v[10][10], ret, cnt
���� : ��ȸ��, v�ʱ�ȭ, cnt �ʱ�ȭ, ret�ִ� ���� -1 ����,
		dfs���� ���̷��� ��� ����, ���� ��� ��� ����  
��谪 :  �𼭸��� ���̷��� �ϳ���, ��𼭸��� �ϳ��� 
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
			
			else if ( a[ny][nx]==2 || cnt==-1 ) //���̷��� 
				cnt = dfs(ny,nx,-1);
			
			else cnt = dfs(ny,nx,cnt+1); //�Ϲݽ���  
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
					case 1 : v[i][j] = -1000; break; // �� 
					case 2 : dfs(i,j,-1); break; // ���̷���
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

