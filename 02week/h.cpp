/* 
// T=?, s<=20 end�� ������ ����/
// ���� : a,e,i,o,u �ݵ�� ����, ee,oo ���
// idea : endȮ��, ����ī����, ����ī����, �ٷ��� ���, �������翩��, eeoo ����ó �� 
// �ð����⵵ : len(s)*T 20*T < 1�� (T<5��) 
�ڷᱸ�� : s, aeo, zxc, b,ret;  
 ���� : s �ʱ�ȭ, ret ����, end ������ ���� 
 ��谪 : �������� ���� end ����,  
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

