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
 




/*
idea : 5가 10개 있는것 부터 5개수 하나씩 줄여가면서 범위 내에 5개수 찾기,
1. while(num5=10) 부터 시작해서, 
2.  for(i=1~n) 까지 num5과 곱한다. 곱하는 연산이 빡쎈듯합니다.  
		if(범위 안들어가면) for문 탈출 
3-1.	if(mp[aaa] =존재) 스킵!    
3.	`	cnt += num
4. 	 num5-- 
시간복잡도: (N/5) // 2억 > 1억 이긴한데 가능할듯?  



idea : 10으로 나눠 떨어지면+ 하고, 나누는 것도 10을 미리 한다. 마자막 숫자만 가지고 있는다?
- 안에 있는 2(는 많으니까)와 5의 개수를 찾는다.
- 2. for 전체 숫자 스텝 5씩, 5의 개수 구하기  
시간 복잡도 : N/5 * 9 
*/ 
