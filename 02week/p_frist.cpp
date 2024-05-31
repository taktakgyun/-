/*
����� : 3<= N,M <= 8 / ��ĭ�� 3�̻�, 2<=���̷���<=10 /������������ 
		/ �߰��� 3�� 
�ؼ� : ���� �ùķ��̼�(dfs Ŀ��Ƽ��������Ʈ), ������ �ִ밡 �Ǵ� ã�ƶ�.
���̵�� : 
 
 ���̵�� : �׳� �������� ���
 	1. �������� ���� 3�� �����.
	 	2. for(�������) if(�ȹ湮�� ����(0��))  dfs
	3. �� ����, visited �ʱ�ȭ
	
	dfs. 0�ΰ� �����ؼ� ���� ���ϱ�, �ٵ�, ���̷����� ������ -1��ȯ 
�ð� ���⵵: 62C3 * 64 /  64*62*61*60 / 16�� <2��? ����������? 
�ڷᱸ�� : N,M, a[10][10], v[10][10], cnt, ret; 
���� : v �ʱ�ȭ ret �ִ밪(�ʱ� ����) 
��谪 : �������� 3���� ���� ��,
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
