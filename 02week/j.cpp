/* H<=100, W<=100, �ȶ� ���� -1, �� ���� 0�̻� / ��� �� ������ ���ϱ� 
�⺻ : �������� �̵� dx=1 dy=0
idea : dfs �������θ� �̵���Ű��, �� ������ ������ ��ž/ ������ ���ʺ��� Ȯ��  
- dfs : ���̳� ������ ���������� ����  
- 1. for(���ʺ��� ��� ���� ����)
- 2. 	if(Ŭ�����ΰ�츸 �ϱ�) dfs
�ð����⵵ : nw * w     �鸸 < 1��
�ڷᱸ�� : H, W, i,j, a[100][100],v[100][100],  
���� : v�� -1�� �ʱ�ȭ  
��谪 : ������ ��� �����ΰ��,
		������ �� ���� ���� �ִ°��,
		������ ���� ���� �ִ°��
		hw�� 1�ΰ��, 100,100�ΰ�� 
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

