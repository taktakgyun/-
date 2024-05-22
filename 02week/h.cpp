/* 
// T=?, s<=20 end가 나오면 종료/
// 이해 : a,e,i,o,u 반드시 포함, ee,oo 허용
// idea : end확인, 모음카운팅, 자음카운팅, 바로전 기억, 모음존재여부, eeoo 예외처 리 
// 시간복잡도 : len(s)*T 20*T < 1억 (T<5만) 
자료구조 : s, aeo, zxc, b,ret;  
 조심 : s 초기화, ret 독립, end 나오면 종료 
 경계값 : 시작하자 마자 end 나옴,  
*/
#include<bits/stdc++.h>
using namespace std;
int acnt, zcnt;
char b; 
string s, ret;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	 
	while(1){
		// init
		zcnt = 0; acnt=0; b=(char)0; 
		bool flag = false; 
		// input
		cin >> s;
		// end 
		if (s == "end") break; 
		// calc
		for(char a:s){
			if(a == b && !(a=='e' || a=='o')) {// same 
				flag = false;
				break; 
			}
			b = a; // remember b 
			
			// counting 
			if(a=='a' || a=='e' ||a=='i' ||a=='o' ||a=='u'){
				flag = true;
				acnt++;
				zcnt=0; 
			}
			else{
				zcnt++;
				acnt =0; 
			}
			
			// check 
			if (acnt >=3 || zcnt >= 3){
				flag = false;
				break; 
			} 
		} 
		
		// output
		if (flag) ret += "<"+s+"> is acceptable.\n";
		else ret += "<"+s+"> is not acceptable.\n"; 
	} 
	
	// output
	cout << ret;
	return 0; 
} 

