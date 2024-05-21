// 10 >= N > M > 1/ J<=20  / N 스크롤 M 바구니 / 이동거리 최소
// idea : 거리구현, 바구니 포함해서 위치 차를 구한다. (그리디 알고르즘) 
// 조건 : 다음 위치와 이전 위치 차이이(바구니 때문)
// 1. 반복문 -사과 위치(모든 사과를 떨어트리기)
// 2. 	if (사과 위치 > 현 위치) move = max(사과위치 - 현위치 - 바구니 크기, 0)
// 3.	else(이전이라면) move = 현 위치 - 사과위치
// 4. 	ret += abs(move) / 현 위치 += move 
// 시간 복잡도 : J / 20< 1억 
// 자료구조 : N, M, J, move, ret, cur 
// 조심 : 바구니 길이에 따라 다른 연산에 주의 

#include<bits/stdc++.h>
using namespace std;
int N, M, J, t, mv, ret, cur=1;

int main(){
	// input
	cin >> N >> M >> J;
	M--; 
	while(J--){
		// input
		cin >> t;
		
		// calc 
		if(t > cur) mv = max(t - cur - M, 0);
		else  mv = t - cur;
		
		ret += abs(mv);
		cur += mv; 
	}
	cout << ret << "\n"; 
} 
 
