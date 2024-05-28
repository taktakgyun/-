/*
입출력: T?? , 2<=len(s)<=50 / No, YES
아이디어 : stack을 활용해서 터트리자
1. (가 들어오면 stk에 넣음
2. if(있는거 확인)  )가 들어오면 stk에서 꺼냄
3. 끝났는데 들어있으면 NO 아니면 YES
시간복잡도 : T*len / T*50 < 1억 
자료구조 : T, ret, s, stk 
조심 : 초기화 필수, 이거 순서 조심해야 할듯?  또 터트리는거 조 심  
경계값 : 밑에서 다해준듯? 
*/
#include<bits/stdc++.h>
using namespace std;
int T;
string ret, s;

bool check(string S){
	stack<char> stk;
	for(char c:S){
		if(c=='(') stk.push(c);
		else{
			if(stk.size()) stk.pop();
			else return false; 
		} 
	}
	return stk.empty(); 
} 

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	// input
	cin >>  T;
	
	while(T--){		 
		//input
		cin >> s;
		// calc
		if(check(s)) ret += "YES\n";  
		else ret += "NO\n";
	}
	// output
	cout << ret;
	return 0; 
} 
