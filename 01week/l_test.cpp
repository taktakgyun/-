// idea N + M 
// 1. 개수 카운팅 2.  반 위치까지 존재하는거 확인해서 카운팅
// 자료구조 : N,M, cnt[100000+4]
// 경계값 1. M>200000, 2. cnt[M-i] 인덱스, 3. M이 홀수는 괜찮, 짝 M이면 자기가 둘  
// 1-> M <= 200000 
// 2-> max(M-100000,0)<=i<=(M/2, max_v), // M-i <= 100000 -> i >= max(M-100000,0) 
// 3-> M/2 == M-(M/2) 오류 /  

//경계값 M=9 m+1/2 -1=4  M-i = 4 
//경계값 M=8 m+1/2 -1=3  M-i = 4 오류!  
 

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
    	// 짝수 M : M/2
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

 
