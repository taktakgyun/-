// N <= 100 N*S 2<=lenS<100_000
// idea :
// 1. 받은 값을 스택과 비교해서 같으면 스택빼고, 다르면 스택에 넣음
// 2. 문자 다끝날때, 스택에 남아있으면 안 좋은 문자 3.좋은 문제 ++ 
// 자료구조 : N,ret,S / new st
// 시간복잡도 : O(N)
// 경계값 : 없는듯? / 길수도 있으니 인터럽트 해제

#include<bits/stdc++.h>
using namespace std;
int N, ret;
string s;

int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	// calc 
	while(N--){
		cin >> s;
		stack<char> st;
		for(char c:s){
			if(st.size() && st.top()==c) st.pop();
			else st.push(c); 
		}
		if(st.size()==0) ret++; 
	} 
	
	// output
	cout << ret << "\n"; 
} 
