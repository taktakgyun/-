// T<=100 0=<N<30, k<=20 ==> ����� �� 
// �̸� ����, ���� ������ �ϳ���, ��� ������ ���϶�. �˸��� �ƴϸ� ��
// �������� ������ ����.
// �ش� ������ ������ ���Ѵ�. ���Դ� �͵� �����ؼ�
// (���� + 1)*(���� +1) .... -1 / N=0�� �ΰ� ó�� 

# include<bits/stdc++.h>
using namespace std;
int T, N;
string ret, t1, t2;
int main(){
	// input
	cin >> T;
	
	// case 
	while(T--){
		// input 
		cin >> N;
		// ����ó�� 
		if (N==0){
			ret += "0\n"; 
			continue; 
		} 
		
		// input and set 
		map<string, int> c;
		long long v=1; 
		for(int i=0; i<N; i++){
			// input 
			cin >> t1 >> t2;
			c[t2]++; 
//			auto it = c.find(t2);
//			if(it == c.end()){// frist 
//				c[t2] = 1; 
//			} else{
//				c[t2] += 1; 
//			} 
		} 
		
		// calc 
		for(auto it:c){
			 v *= (long long)(it.second + 1); 
		} 
		
		ret += to_string(--v)+"\n"; 
	}
	// output 
	cout << ret; 
	return 0; 
} 
