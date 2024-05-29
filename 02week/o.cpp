/*
����� : len(s)<= 100 , ������ . ���� / ������ ���� yes no
�ؼ� : (�� )�͸�, [�� ]�͸�, 1��1 ��Ī, 
���̵�� : ������ ���/ (�� [ �� ������ �ְ�, ),]�� ������ ������. 
	- for(���ڿ��� ���� �� ����)
		if( (�� [ �̸�) stk�� �ִ´�.
		else if( ),]   ) 
			if (stk.empty()) ���� 
			else stk����  ),] �������� �ٸ���!  ����, ���̸� pop
	- stk empty���� 
�ð� ���⵵ : T*len(s) / T*100 < 1�� (T<10��)
�ڷᱸ�� : s,ret,stk
���� : �Է� ���� ���� . �����ö�./  ���ȣ ���� /  . �տ� �� ���ö�, 
��谪 : Z�� [�� �� ���� �ȳ� 
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
