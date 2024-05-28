/*
입출력 : N<=10_000 만 / N번째 영화 제목에 들어간 수
해석 : 1은 666 이고 1증가할 때마다 1천씩 증가
 		숫자가 6이 나오는 순간 경우에 수가 6개가 늘어난다.
아이디어 : 숫자 카운팅 하고,  666 찾으면, 스탑하 자  
1. n=666, for(cnt = 0; cnt <= N; cnt++)
2.		 		while(to_string(n).find("666")) n++;
시간복잡도 : 2억 안으로 가능한가는 나중에 보자
자료구조 : N, n, cnt 
조심 : longlong 으로 커버 안될 것 같은데? 
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
