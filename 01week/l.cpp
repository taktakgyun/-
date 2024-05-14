// N< 15_000 M <= 10_000_000
// 특정 2개 수를 합하면 됨 
// 아이디어 : n n-1 /2 조합
// 시간 n^2  125_000_000 200_000_000
// 자구 : N,M,  a[], ret

#include<bits/stdc++.h>
using namespace std;
int N, M, ret, a[15004];

int main(){
	// input 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	cin >> M;
	
	for( int i=0; i<N; i++){
		cin >> a[i];
	} 
	
	if( M <= 200000) { 
		// calc 
		for(int i=0; i<N-1; i++){
			for(int j=i+1; j<N; j++){
				if( a[i] + a[j] == M) ret++; 
			}  
		}
	} 
	// output
	cout << ret << "\n"; 
} 
