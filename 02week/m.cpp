/*
����� : N<=10_000 �� / N��° ��ȭ ���� �� ��
�ؼ� : 1�� 666 �̰� 1������ ������ 1õ�� ����
 		���ڰ� 6�� ������ ���� ��쿡 ���� 6���� �þ��.
���̵�� : ���� ī���� �ϰ�,  666 ã����, ��ž�� ��  
1. n=666, for(cnt = 0; cnt <= N; cnt++)
2.		 		while(to_string(n).find("666")) n++;
�ð����⵵ : 2�� ������ �����Ѱ��� ���߿� ����
�ڷᱸ�� : N, n, cnt 
���� : longlong ���� Ŀ�� �ȵ� �� ������? 
*/

#include<bits/stdc++.h>
using namespace std;
int N;

int main(){
	// input
	cin >> N;
	 
	// calc
	int i=666;
	while(--N){
		i++; 
		while(to_string(i).find("666") == string::npos ) i++; 
	}
//	for(;;i++){
//		if (to_string(i).find("666") != string::npos) N--;
//		if (N==0) break; 
//	} 
	
	//output
	cout << i << "\n"; 
	return 0; 
} 
