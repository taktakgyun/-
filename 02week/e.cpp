// 1<=N<=64 / ������ 
//  idea : ������ �ݶ�����, ��ġ�鼭 4�� �� ������ ��ġ��, �ٸ��� �״��
// 1. sol(y1,x1,y2,x2)
// 2. 	if(y1==y2 and x1==x2) return a[y1][x1]
// 3. 	for(���� �ݺ�)
// 3-1.		sol 4���� �ɰ��� ȣ��! 
//			ret += 4���� ���� �� ������ �ϳ��� ����, 
//			ret += 4���� ���� �ٸ��� ������� ���ڿ��� ��ȯ
// 4. 	return ret 
// �ð����⵵ : 4*N(logN+1) /  4*64*7 -> 2 11��(2��) < 2�� 
// �ڷᱸ�� : N, a[65][65]  
// ���� : �ð��� 2��???, �Է��� �پ� ���� 
// ��谪 : OOI, ���ɰ��鼭 ���� ����, ��ȣ ����(Ư�� �����ϸ鼭)
// 		N=1�ΰ� �׽�Ʈ, N=64 ���� ������ ���� �ٸ��� �׽�Ʈ

#include<bits/stdc++.h>
using namespace std;
int N, a[64][64];
string RET;

string sol(int y1, int x1, int y2, int x2){
	// end
	int ygap = y2-y1, xgap=x2-x1; // 8 
	int yh = ygap/2, xh=xgap/2; // 4 
	if(ygap==1 && xgap==1) return to_string(a[y1][x1]); 
	
	string ret; 
	// re
	string aa,bb,cc,dd;
	aa = sol(y1, 		x1, 	y1+ yh,	x1+xh); // 00 , 44 
	bb = sol(y1, 		x1+xh, 	y1+ yh,	x2); // 04 , 48 
	cc = sol(y1+ yh, 	x1, 	y2, 	x1+xh);//40, 84 
	dd = sol(y1+ yh, 	x1+xh, 	y2, 	x2);//44,88 
	if(aa.size()==1 && aa==bb && aa==cc && aa==dd) ret = aa;
	else{
		ret = "("+aa+bb+cc+dd+")"; 
	}	
	return  ret; 
} 

int main(){
	// input 
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%1d", &a[i][j]); 
		} 
	}

	// calc
	RET = sol(0,0, N, N); 
	
	// output
	cout << RET<<"\n"; 
	return 0; 
	
//	// ```````````````
//	cout << "�����ض�\n"; 
//	for(int i=0; i<N; i++){
//		for(int j=0; j<N; j++){
//			printf("%2d", a[i][j]); 
//		}
//		cout << endl; 
//	}
} 
