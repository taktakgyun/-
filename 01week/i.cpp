// 전체 N, 문제 M 입력 100_000, K 2~20
// text2int(dict) int2text(vector 를 만든다. 
// 빠른 입력 필수
#include<bits/stdc++.h>
using namespace std;
int N,M, num;
string int2str[100004], ret="",t;
map<string, int> str2int;
 
int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=1; i<=N; i++){
		cin >> int2str[i];
		str2int[int2str[i]] = i; 
	} 
	
	// calc 
	while(M--){
		cin >> t;
		num = atoi(t.c_str());
		if(num == 0) ret += to_string(str2int[t]);
		else ret += int2str[num];
		ret += "\n"; 
	} 
	
	// output
	cout << ret; 
	
} 


//#include <bits/stdc++.h>
//using namespace std;
//
//int N, M, num;
//map<string, int> t2i;
//string i2t[100004], temp, ret=""; 
//
//int main(){
//	// input
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
//	
//	cin >> N >> M;
//	
//	for(int i=1; i<=N; i++){
//		cin >> temp;
//		i2t[i] = temp;
//		t2i.insert({temp, i}); 
//	}
//	
//	// calc
//	for(int i=0; i<M; i++){
//		cin >> temp; 
//		num = atoi(temp.c_str());
//		if ( num != 0 ){
//			ret += i2t[num] + "\n"; 
//		}else{
//			ret += to_string(t2i[temp]) + "\n"; 
//		} 
//	}
//	
//	// output
//	cout << ret; 
//} 
// 
 
