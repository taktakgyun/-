/*
����� : N<=10_000 �� / N��° ��ȭ ���� �� ��
�ؼ� : 1�� 666 �̰� 1������ ������ 1õ�� ����
 		���ڰ� 6�� ������ ���� ��쿡 ���� 6���� �þ��.
���̵�� : ������ ����� ����� ���� ã�´�.
		�������� ���� ã��,
		���� ���̸� �ش� ���� ó������ �����Ѵ�. 
		1�ڸ� ����, ���ڸ� ����, ���ڸ� ���� ����.
1. for( 1�ڸ�������)
	if (cnt+������ < N) cnt+������
	else �ڸ����� cnt, ���� ������ ì�ܼ� ������
2. n=�ش� �ڸ����� �ּҰ�, for(cnt = 0; cnt <= N; cnt++)
3.		 						while(!find_666(n)) n++;
 
�ڷᱸ�� : N, cnt, num_n, permut 
		 
���̵�� : ���� ī���� �ϰ�,  666 ã����, ��ž�� ��  
1. n=666, for(cnt = 0; cnt <= N; cnt++)
2.		 		while(!find_666(n)) n++;
�ð����⵵ : 2�� ������ �����Ѱ��� ���߿� ����
�ڷᱸ�� : N, n, cnt 
���� : longlong ���� Ŀ�� �ȵ� �� ������? 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ; 
int N, num_n, permut;

int a[6] = {1,2,6,20,70,504}; 

int main(){
	//input
	cin >> N;
	
	// calc
	int cnt=1;
	ll nine = 1;
	ll n=666;
	ll nn=0; 
	if(N>1){
		for(num_n=1; num_n<6; num_n++, nine *= 10){ 
			permut = (a[num_n]*9)* nine;
			cout << cnt << "|"<<a[num_n]<<"|"<<nine<<"|"<<permut<<endl; 
			if(cnt + permut < N)   cnt += permut;
			else break; 
		} 
		
		for(int i=0; i<num_n; i++){
			if(nn==0)  nn=100; 
			nn *= 10; 
		}
		n += nn;
		n--; 
	}
	cout << n << endl;
	 
	for(; cnt<N; cnt++){
		n++; 
		while( to_string(n).find("666") == string::npos ) n++; 
	} 
	
	// output
	cout << n << "\n";
	return 0; 
} 
