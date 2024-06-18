/*
����� : H, W <=100, �����ڸ��� ����, 0���� 1 ġ��
		��γ����� ���� �ð�, �� �ٷ��� ���� ����
���̵�� : �������� CC �ϰ�, ġ� ������ ǥ����
	1. 0,0�� �������� dfs �ؼ� CC����
	2. ���� ġ�� ���� ���ϰ�, ġ�� ����
	3. if ���� ġ�� Ȯ�� / T , ���� ġ�� ��� 
	3. else ��� ���� / T++,  
	4.  
�ð����⵵ : 50 * (N*N) 
�ڷᱸ�� : H,W,A,V,dxdy, Chz,T, cnt 
��谪 : 
	- �ƹ��͵� ������,
	- �ϳ��� ���� ��
	- ��á��, 
*/
#include<bits/stdc++.h>
using namespace std;
int H,W, A[104][104], V[104][104], T,cnt;
int dx[4]={1,0,-1,0}, dy[4]={0,-1,0,1};
vector<pair<int,int>> Chz;

void dfs(int y, int x){
	// start
	V[y][x] = 1;
	
	// end
	if(A[y][x] == 1){
		Chz.push_back({y,x}); 
		return; 
	}
	
	// re
	for(int i=0; i<4; i++){
		int ny= y+dy[i];
		int nx= x+dx[i];
		if(ny>=0 && ny<H &&  nx>=0 && nx<W){
			if(V[ny][nx]==0) dfs(ny,nx); 
		} 
	}
	return; 
}

bool check_chz(){
	for(int i=0; i<H; i++){
		for( int j=0; j<W; j++){
			if(A[i][j]==1) return true; 
		} 
	}
	return false; 
} 

int main(){
	// input
	cin >> H >> W;
	for(int i=0; i<H; i++){
		for( int j=0; j<W; j++){
			cin >> A[i][j]; 
		} 
	} 
	// calc
	while(1){
		// init
		memset(V, 0, sizeof(V));
		Chz.clear(); 
		
		// set Ŀ��ƼƮ ������Ʈ
		dfs(0,0);
		
		// ġ�� ���̱� 
		cnt = Chz.size();
		for(auto a : Chz){
			A[a.first][a.second] = 0; 
		}
		T++;
		// �� ����� ��
		if(!check_chz()) break;
	} 
	// output 
	if( cnt == 0 ) cout << "0\n0\n";
	else cout << T << "\n"<<cnt<<"\n";
	
	return 0; 
} 
