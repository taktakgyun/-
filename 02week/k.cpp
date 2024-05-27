/*
����� : T<??? N<10�� / 0�� ������ ���ض�
idea : N���� 5�� ���� ����, �� ���� �ű⿡�� �� ������ ���� �ݺ�
- 1. while N >= 5
- 2.	cnt += (N = N/5) 
�ð� ���⵵ : log5N // 10*T < 1�� (T<õ��) 
�ڷᱸ�� : T, N, cnt, ret 
���� : ���� �շ����� ���� �Ұ� // ���ɶ� cnt �ʱ�ȭ // long long ����  
��谪 : 10���, 1,5 �ε�?  
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
string ret; 
ll N, cnt;

int main(){
	//input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while(T--){
		// init
		cnt = 0;
		
		// input
		cin >> N;
		
		// calc
		while( N>=5 )  cnt += (N = N/5) ; 
		
		// output
		ret += to_string(cnt)+"\n"; 
	} 
	
	// output
	cout<<ret; 
	return 0; 
} 
 

