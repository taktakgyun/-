/*
입출력 : len(s)<= 100 , 무조건 . 포함 / 균형에 따라 yes no
해석 : (는 )와면, [는 ]와만, 1대1 매칭, 
아이디어 : 스택을 사용/ (와 [ 가 있으면 넣고, ),]가 있으면 꺼낸다. 
	- for(문자열이 끝날 때 까지)
		if( (와 [ 이면) stk에 넣는다.
		else if( ),]   ) 
			if (stk.empty()) 거짓 
			else stk에서  ),] 꺼낼때와 다르면!  거짓, 참이면 pop
	- stk empty인지 
시간 복잡도 : T*len(s) / T*100 < 1억 (T<10만)
자료구조 : s,ret,stk
조심 : 입력 종료 조건 . 만들어올때./  겹괄호 조심 /  . 앞에 뭐 들어올때, 
경계값 : Z와 [가 얼마 차이 안남 
*/
#include<bits/stdc++.h>
using namespace std;
string s, ret;

bool check(string str){
	stack<char> stk;
	
	for(char c : str){
		if( c=='(' || c=='[' ) stk.push(c); 
		else if( c==')' || c==']' ){
			if(stk.empty()) return false;
			
			char temp = stk.top(); stk.pop();
			if(temp != c-2 && temp != c-1) return false; 
		} 
	} 
	return stk.empty(); 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	while(1){
		//input
		getline(cin, s); 
		if(s == ".") break; 
		// calc
		if(check(s)) 	ret+="yes\n"; 
		else			ret+="no\n";
	}
	cout << ret;
	return 0; 
} 
