// 그냥합 n**2 나온다. 10^10 나온다. 
// 1. i in 0~n-k 까지 반복한다. 
// 2. i~i+k 까지 합을 구해서 최대값을 저장하고 있는다. (n-k)k = nk + k**2 

// 누적합 N 
// 1. 이전 합들을 모두 기록한다.
// 2. 계산을 할 때 개수에 맞도록 변경한다.
#include<bits/stdc++.h>
using namespace std;
const int LEN = 100000;
int sum[LEN+4]={0, }, N, K, temp, ret=-100000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	// input
	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> temp;
		sum[i] = sum[i-1] + temp; //sum 
	}
	
	// calc
	for(int i=K; i<=N; i++){
		temp = sum[i] - sum[i-K]; 
		ret = max(ret, temp); 
	}
	
	// output
	cout << ret << "\n";
	return 0; 
} 


 
