// 1<=K <=50 / fail sorry
// idea : �⺻������ ¦�������� �� �������. �� Ȧ������ �� �Ѱ� �ΰ�쵵 ����� 
// 1. ���ڸ� ���� ���� ����.
// 2. ���������� �տ� �ִ� �ͺ��� �ؼ� ���� ��ŭ����ϰ�, �����ؼ� �ϳ��� �Ѵ�.
// ��谪 : Ȧ������ ��츦 �� ó���� �ٰ�, �Ѱ� �ΰ� ��  
// ���������� ���
// �ð� ���⵵ :  K
// �ڷᱸ�� : 26���� ���ĺ� ī����, Ȧ������ �ε��� 0�� ���°�
// ���� : ���� ¦����, Ȧ���� 2�� �̻�    

#include<bits/stdc++.h>
using namespace std;

int cnt[128], odd;
string s, ret, temp;

int main(){
	// input
	cin >> s;
	
	// calc
	for(char c : s) cnt[(int)c]++; 
	
	// befor 
	for(int i='A'; i<='Z'; i++){
		if (cnt[i] > 0 ){
			if (cnt[i] % 2 == 1 ){//odd 
				if(odd >='A'){ // already end 
					cout <<  "I'm Sorry Hansoo\n";
					return 0; 
				}
				odd = i; 
			}
			int k = cnt[i] / 2;
			while(k--) ret += (char) i; 
		} 
	} 
	
	// output 
	cout << ret;
	if (odd >= 'A') cout << (char)odd;
	reverse(ret.begin(), ret.end());
	cout << ret<<"\n";
	
	return 0; 
} 
