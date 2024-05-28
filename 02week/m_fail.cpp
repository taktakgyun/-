/*
입출력 : N<=10_000 만 / N번째 영화 제목에 들어간 수
해석 : 1은 666 이고 1증가할 때마다 1천씩 증가
 		숫자가 6이 나오는 순간 경우에 수가 6개가 늘어난다.
아이디어 : 순열을 사용한 경우의 수를 찾는다.
		단위별로 개수 찾고,
		범위 안이면 해당 범위 처음부터 시작한다. 
		1자리 순열, 두자리 순열, 세자리 순열 구함.
1. for( 1자릿수부터)
	if (cnt+순열값 < N) cnt+순열값
	else 자릿수와 cnt, 나중 순열값 챙겨서 나오기
2. n=해당 자릿수의 최소값, for(cnt = 0; cnt <= N; cnt++)
3.		 						while(!find_666(n)) n++;
 
자료구조 : N, cnt, num_n, permut 
		 
아이디어 : 숫자 카운팅 하고,  666 찾으면, 스탑하 자  
1. n=666, for(cnt = 0; cnt <= N; cnt++)
2.		 		while(!find_666(n)) n++;
시간복잡도 : 2억 안으로 가능한가는 나중에 보자
자료구조 : N, n, cnt 
조심 : longlong 으로 커버 안될 것 같은데? 
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
