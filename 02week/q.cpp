/*
����� : H,W<=100 , 0(X), 1(ġ��)  / ġ�� ��� ����, 1�ð���
�ؼ� :
	1. ġ���� ǥ���� ã�´�.
	2. ġ�� ǥ���� ���ش�.
	3. ��ð��� ������ ġ� �� ����� ���Ѵ�. 
	extra. ������ �� ġ��� �����? 
�м� : 
	- ������ Ŀ��Ƽ�� ������Ʈ�� ���Ѵ�.(�����ڸ��κи�)
	- �� ��� ġ�� CC�� ���Ѵ�.(�ֺ��� ������ ���� ���� ��)
	- �ð��� ī�����ϰ� ���� ģ���� �ʱ�ȭ �Ѵ�.
���̵�� : ������ CC�� �� ���� ġ�� CC�� ���Ѵ�! 
	- ���� �ݺ� / ���߿� �ȳ��� ġ�� ������ ����
		- ������ CC ���ϱ�
		- �� ���� CC ���ϱ�
		- �� ���� ġ�� ���� ���ϱ� / �ð�++ 
		- if(�ȳ��� ġ�� ������ ) ����
		- else ���� ���� �ȳ��� ġ��� �ʱ�ȭ �ϱ�
�ð� ���⵵ : (N/2)=AA  / AA*(4*N+N*N)  / 50*(400+��) = 50�� < 1�� 
�ڱ� : H,W, A[102][102], Air[102][102], Chz[102][102],T  
���� : ������ CC, �� ���� ġ�� CC �ʱ�ȭ �� �Ұ�, ġ��1������ �ϱ�  
��� : ��� ġ� ����, ġ�� �ϳ��� ����  
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
	for(int i=0; i<4; i++){ // �ֺ��� ���� ���� �Ǻ� 
		int ny = y+dy[i];
		int nx = x+dx[i];
		// �ֺ��� �ϳ��� ����� ��û  
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
