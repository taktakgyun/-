// 0 < A B C < int의 max 값 
// idea : B제곱을 반씩 나눠서 결과를 모듈러 해서 나누는 로직을 구한다. 홀수 짝수 구별
// -> B홀 (B-1)함 1. 반구하기  2. 반*반*a 
// 시간복잡도 : O(logB) 21 < 5천만  
// 자료구조 : A B C
// 경계값 : 매우 큰값 / C 가 AB 보다 엄청큼 / B가 엄청큼 / A%C가 엄청큼 / B가 1 
// 대응 : long log 으로 대응


#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll A, B, C;


ll calc(ll a, ll b, ll c){
	// end
	if(b == 1)return a;
	
	ll ap = 1; 
	if (b & 1) ap = a; // odd 
	// re
	ll hf = calc(a, b/2, c);
	
	return (((hf * hf)%c) * ap) %c; 
}  

int main(){
	// input
	cin >> A >> B >> C;
	
	// calc
	ll ret =1;
	ret = calc(A%C, B, C); 
	cout << ret<<"\n"; 
}

// 폐기    
// idea : ((A%C)^B)%C 
// 시간복잡도 : O(B) 21억 > 5천만  
