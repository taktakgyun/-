/*
����� : 3<=N,M<=8, 0��1��2��
		��<=10, 3<=��
		�ִ� ���� ������  ũ��
�ؼ� :
	1. �� 3�� �����
	2. ���̷��� ��Ʈ����
	3. �������� �� ���� 
���̵�� : �������� ��������, ���̷����� CC��, �������� ���ϱ�
	1. �� 3�� �����
		2. for(��� ���̷��� ��ġ) dfs()
		3. for(��翵��) if(v ��������, a ��ĭ) cnt++
	4. �� ���� 
�ð����⵵ : 62C3 * (64+64) / 62*61*60*120/3 = 4õ�� < 1��
�ڷᱸ�� : N,M,ret,a[10][10],v[10][10], bius,zero 
���� : ret �ִ밪, v�ʱ�ȭ, ������ 
*/

#include<bits/stdc++.h>
using namespace std;
int N,M,ret, a[10][10], v[10][10], wall;
vector<pair<int,int>> bius, zero;

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1}; 
int dfs(int y, int x, int cnt){
	// start
	v[y][x] = cnt;
	
	// re
	for(int i=0; i<4; i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny>=0 && ny < N&&  nx>=0 && nx < M && a[ny][nx] == 0 && v[ny][nx] ==0){
			cnt = dfs(ny,nx,cnt+1); 
		} 
	} 
	
	//
	return cnt; 
} 

int go(){
	// init
	memset(v, 0, sizeof(v));
//	fill(&v[0][0], &v[0][0] + 10 * 10, 0);
	int cnt =0;
	
	// dfs
	for(auto b : bius){
		cnt = dfs(b.first, b.second, cnt+1); 
	} 
	
	// count 
	return N * M - wall -3 - cnt; 
} 

int main(){
	// input
	cin >> N>>M;
	for(int i=0; i< N; i++){
		for(int j=0; j<M; j++){
			cin >> a[i][j];
			switch(a[i][j]){
				case 2: bius.push_back({i,j});break;
				case 0: zero.push_back({i,j});break;
				case 1: wall++;break; 
			} 
		} 
	}
	
	// calc
	int NUM = zero.size(); 
	for(int i=0; i<NUM-2; i++){
		for(int j=i+1;j<NUM-1; j++){
			for(int k=j+1;k<NUM; k++){
				pair<int,int> t;
				t =  zero[i]; a[t.first][t.second] = 1; 
				t =  zero[j]; a[t.first][t.second] = 1;
				t =  zero[k]; a[t.first][t.second] = 1;
				
				ret = max(ret, go()); 
				
				t =  zero[i]; a[t.first][t.second] = 0; 
				t =  zero[j]; a[t.first][t.second] = 0;
				t =  zero[k]; a[t.first][t.second] = 0;
			} 
		} 
	} 
	
	// output
	cout << ret << "\n";
	return 0; 
} 
