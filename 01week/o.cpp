// T < ? / 1<=n<10_000 -> 가장 작은 1111 배수
// idea : 1부터 *10 +1 한 값에 n을 나눠본다. 2. 안되면 (*10+1)%n 으로 갱신 3.  
// 시간복잡도: O(T * log10_(큰수)) T*4500 < 1억 (T<=2만개) 
// 자료구조 : n, a(나눌거), ret(자릿수) 
// 경계값 : ret이 엄청 클 경우 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n;
ll a, ret;

int main(){
	while( scanf("%d", &n) != EOF ){// inupt 
		// calc
		for(a=1,ret=1; a % n; a=(a*10+1)%n,ret++ ){ }
		// output
		cout << ret << "\n"; 
	} 
} 

// 폐기      
// idea : 1부터 *10 +1 한 값에 n을 나눠본다. 2. 나눠지면 바로 출력
// 시간복잡도: O(T * log10_(큰수) * (큰수/n) / 2) T*3000*1000 > 1억 ( T>10 ) 
// 경계값 : T가 10개만 되도 시간 오버, 큰수가 long long 으로 커버가 안됨  


//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll; 
//int n;
//ll a, ret;
//
//int main(){
//	while(1){// inupt 
//		// calc
//		cin >> n;
//		if(cin.eof()) break; 
//		for(a=1,ret=1; a % n; a=(a*10+1)%n,ret++ ){ }
//		// output
//		cout << ret << "\n"; 
//	}
//} 
