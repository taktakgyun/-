/*
�����: T?? , 2<=len(s)<=50 / No, YES
���̵�� : stack�� Ȱ���ؼ� ��Ʈ����
1. (�� ������ stk�� ����
2. if(�ִ°� Ȯ��)  )�� ������ stk���� ����
3. �����µ� ��������� NO �ƴϸ� YES
�ð����⵵ : T*len / T*50 < 1�� 
�ڷᱸ�� : T, ret, s, stk 
���� : �ʱ�ȭ �ʼ�, �̰� ���� �����ؾ� �ҵ�?  �� ��Ʈ���°� �� ��  
��谪 : �ؿ��� �����ص�? 
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
