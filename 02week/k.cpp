/*
입출력 : T<??? N<10억 / 0의 개수를 구해라
idea : N에서 5로 나눠 놓고, 그 개수 거기에서 또 나누고 개수 반복
- 1. while N >= 5
- 2.	cnt += (N = N/5) 
시간 복잡도 : log5N // 10*T < 1억 (T<천만) 
자료구조 : T, N, cnt, ret 
조심 : 절대 롱롱으로 감당 불가 // 테케라 cnt 초기화 // long long 으로  
경계값 : 10억과, 1,5 인듯?  
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
 

