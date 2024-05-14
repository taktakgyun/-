// idea N + M 
// 1. ���� ī���� 2.  �� ��ġ���� �����ϴ°� Ȯ���ؼ� ī����
// �ڷᱸ�� : N,M, cnt[100000+4]
// ��谪 1. M>200000, 2. cnt[M-i] �ε���, 3. M�� Ȧ���� ����, ¦ M�̸� �ڱⰡ ��  
// 1-> M <= 200000 
// 2-> max(M-100000,0)<=i<=(M/2, max_v), // M-i <= 100000 -> i >= max(M-100000,0) 
// 3-> M/2 == M-(M/2) ���� /  

//��谪 M=9 m+1/2 -1=4  M-i = 4 
//��谪 M=8 m+1/2 -1=3  M-i = 4 ����!  
 

#include<bits/stdc++.h>
using namespace std;
int N,M, ret, cnt[100004], temp, max_v=-11111;
int main(){
	// intput
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++){
		cin >> temp;
		cnt[temp]++;
		max_v = max(max_v, temp); 
	}
	// calc
	if(M <= 200000)
    {
    	// ¦�� M : M/2
    	if ( M/2 == M-(M/2) ){
			ret += cnt[M/2] / 2; 
		}
		
    	//  max(M-100000,0)<=i<=((M+1)/2 -1, max_v)
    	temp =  max(M-100000,0); 
    	for(int i = min((M+1)/2-1, max_v); i >= temp; i--)
        {
        	ret += min(cnt[i], cnt[M-i]);
        }
    }
	// output
	cout << ret << "\n";       
} 

 
