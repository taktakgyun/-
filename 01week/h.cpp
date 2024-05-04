// �׳��� n**2 ���´�. 10^10 ���´�. 
// 1. i in 0~n-k ���� �ݺ��Ѵ�. 
// 2. i~i+k ���� ���� ���ؼ� �ִ밪�� �����ϰ� �ִ´�. (n-k)k = nk + k**2 

// ������ N 
// 1. ���� �յ��� ��� ����Ѵ�.
// 2. ����� �� �� ������ �µ��� �����Ѵ�.
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


 
