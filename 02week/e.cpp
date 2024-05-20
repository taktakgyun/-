// 1<=N<=64 / 압축결과 
//  idea : 무조건 반때리고, 합치면서 4개 다 같으면 합치고, 다르면 그대로
// 1. sol(y1,x1,y2,x2)
// 2. 	if(y1==y2 and x1==x2) return a[y1][x1]
// 3. 	for(범위 반복)
// 3-1.		sol 4개로 쪼갠거 호출! 
//			ret += 4개를 보고 다 같으면 하나도 통합, 
//			ret += 4개를 보고 다르면 순서대로 문자열로 반환
// 4. 	return ret 
// 시간복잡도 : 4*N(logN+1) /  4*64*7 -> 2 11승(2만) < 2억 
// 자료구조 : N, a[65][65]  
// 조심 : 시간이 2초???, 입력이 붙어 있음 
// 경계값 : OOI, 반쪼개면서 오류 조심, 괄호 조심(특히 통합하면서)
// 		N=1인거 테스트, N=64 전부 같은거 전부 다른거 테스트

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
//	cout << "삭제해라\n"; 
//	for(int i=0; i<N; i++){
//		for(int j=0; j<N; j++){
//			printf("%2d", a[i][j]); 
//		}
//		cout << endl; 
//	}
} 
