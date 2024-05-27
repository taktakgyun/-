/*
����� : T<??? N<10�� / 0�� ������ ���ض�
idea 
�ڷᱸ�� : T, N, cnt,temp, mp, ret 
���� : ���� �շ����� ���� �Ұ� // ���ɶ� cnt,mp �ʱ�ȭ // long long ����  
��谪 : 10���, 1,5 �ε�?  
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, cnt;
string ret; 
ll N, temp;
const ll init =  5*5*5*5*5*5*5*5*5*5; 

int main(){
	//input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;
	while(T--){
		// init
		cnt = 0;
		map<string, int> mp;
		
		// input
		cin >> N;
		
		// calc
		for(ll num5=init,cnt5=10; cnt5 > 0; num5 /= 5, cnt5--){
			for(ll i=1; i<=200000000; i++){
				temp = num5*i;
				if (temp>N) break;//end 
				int k = ++mp[to_string(temp)];
				if(k > 1) continue; // �̹� ��
				cnt += cnt5;				
			} 
		}
		 
		// output
		ret += to_string(cnt)+"\n"; 
	} 
	
	// output
	cout<<ret; 
	return 0; 
} 
 




/*
idea : 5�� 10�� �ִ°� ���� 5���� �ϳ��� �ٿ����鼭 ���� ���� 5���� ã��,
1. while(num5=10) ���� �����ؼ�, 
2.  for(i=1~n) ���� num5�� ���Ѵ�. ���ϴ� ������ ������մϴ�.  
		if(���� �ȵ���) for�� Ż�� 
3-1.	if(mp[aaa] =����) ��ŵ!    
3.	`	cnt += num
4. 	 num5-- 
�ð����⵵: (N/5) // 2�� > 1�� �̱��ѵ� �����ҵ�?  



idea : 10���� ���� ��������+ �ϰ�, ������ �͵� 10�� �̸� �Ѵ�. ���ڸ� ���ڸ� ������ �ִ´�?
- �ȿ� �ִ� 2(�� �����ϱ�)�� 5�� ������ ã�´�.
- 2. for ��ü ���� ���� 5��, 5�� ���� ���ϱ�  
�ð� ���⵵ : N/5 * 9 
*/ 
