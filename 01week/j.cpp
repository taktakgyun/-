// T<=100 0=<N<30, k<=20 ==> 경우의 수 
// 이름 종류, 같은 종류는 하나만, 모든 조합을 구하라. 알몸만 아니면 됨
// 종류별로 개수를 센다.
// 해당 종류의 조합을 구한다. 안입는 것도 포함해서
// (개수 + 1)*(개수 +1) .... -1 / N=0개 인것 처리 

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
		// 예외처리 
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
