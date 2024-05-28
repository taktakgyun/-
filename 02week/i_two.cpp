/*
자료구조 : N, A,B, CurT, PervT, ret 
*/

#include<bits/stdc++.h>
using namespace std;
int N, A, B,AT,BT, CurT, PrevT, t,mm,ss;
string ret;
const int T = 48*60; 

string to_time(int t){
	string M = "00" + to_string(t/60); 
	string S = "00" + to_string(t%60);
	return M.substr(M.size() - 2, 2) + ":" + S.substr(S.size() - 2, 2); 
}

int main(){
	// input
	cin >> N;
	
	while(N--){
		// input
		scanf("%d %2d:%2d", &t, &mm, &ss);
		
		// calc
		CurT = mm*60 + ss;
		if(A > B) AT += CurT - PrevT;
		else if(B > A) BT += CurT - PrevT;
		if(t==1) A++;
		else B++;
		 
		PrevT = CurT; 
	}
	// calc
	if(A > B) AT += T - PrevT;
	else if(B > A) BT += T - PrevT; 
	
	
	// output
	ret +=  to_time(AT)+"\n";
	ret += to_time(BT); 
	cout << ret;
	return 0; 
} 
