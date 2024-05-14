// T < ? / 1<=n<10_000 -> ���� ���� 1111 ���
// idea : 1���� *10 +1 �� ���� n�� ��������. 2. �ȵǸ� (*10+1)%n ���� ���� 3.  
// �ð����⵵: O(T * log10_(ū��)) T*4500 < 1�� (T<=2����) 
// �ڷᱸ�� : n, a(������), ret(�ڸ���) 
// ��谪 : ret�� ��û Ŭ ��� 

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

// ���      
// idea : 1���� *10 +1 �� ���� n�� ��������. 2. �������� �ٷ� ���
// �ð����⵵: O(T * log10_(ū��) * (ū��/n) / 2) T*3000*1000 > 1�� ( T>10 ) 
// ��谪 : T�� 10���� �ǵ� �ð� ����, ū���� long long ���� Ŀ���� �ȵ�  


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
