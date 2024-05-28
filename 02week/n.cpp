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


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	// input
	cin >>  T;
	
	while(T--){
		// init
		stack<char> stk;
		bool flag = false; 
		 
		//input
		cin >> s;
		
		// calc
		for(char c:s){
			if(c=='(') stk.push(c);
			else if (c==')'){
				if(stk.size()) stk.pop();
				else{
					flag = true; 
					break; 
				} 
			}
		}
		if(stk.size() || flag)  ret += "NO\n";
		else ret += "YES\n";  
	}
	
	// output
	cout << ret;
	return 0; 
} 
