// 0 < A B C < int�� max �� 
// idea : B������ �ݾ� ������ ����� ��ⷯ �ؼ� ������ ������ ���Ѵ�. Ȧ�� ¦�� ����
// -> BȦ (B-1)�� 1. �ݱ��ϱ�  2. ��*��*a 
// �ð����⵵ : O(logB) 21 < 5õ��  
// �ڷᱸ�� : A B C
// ��谪 : �ſ� ū�� / C �� AB ���� ��ûŭ / B�� ��ûŭ / A%C�� ��ûŭ / B�� 1 
// ���� : long log ���� ����


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

// ���    
// idea : ((A%C)^B)%C 
// �ð����⵵ : O(B) 21�� > 5õ��  
