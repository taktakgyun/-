// N <= 100 N*S 2<=lenS<100_000
// idea :
// 1. ���� ���� ���ð� ���ؼ� ������ ���û���, �ٸ��� ���ÿ� ����
// 2. ���� �ٳ�����, ���ÿ� ���������� �� ���� ���� 3.���� ���� ++ 
// �ڷᱸ�� : N,ret,S / new st
// �ð����⵵ : O(N)
// ��谪 : ���µ�? / ����� ������ ���ͷ�Ʈ ����

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
