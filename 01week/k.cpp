// 1<=K <=50 / fail sorry
// idea : 기본적으로 짝수개여야 잘 만들어짐. 단 홀수개가 단 한게 인경우도 만들어 
// 1. 문자를 종류 별로 샌다.
// 2. 사전순으로 앞에 있는 것부터 해서 절반 만큼출력하고, 반전해서 하나더 한다.
// 경계값 : 홀수개인 경우를 잘 처리해 줄것, 한개 두개 등  
// 사전순으로 출력
// 시간 복잡도 :  K
// 자료구조 : 26개의 알파벳 카운터, 홀수개인 인덱스 0은 없는거
// 예외 : 전부 짝수개, 홀수개 2개 이상    

#include<bits/stdc++.h>
using namespace std;
int cnt[128], odd;
string s, ret;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// input
	cin >> s;
	
	// calc
	for(char c : s) cnt[(int)c]++; 
	
	// befor 
	for(int i='Z'; i>='A'; i--){
		if (cnt[i] > 0 ){
			if (cnt[i] & 1){//odd 
				if(odd >='A'){ // already end 
					cout <<  "I'm Sorry Hansoo\n";
					return 0; 
				}
				odd = i; 
			}
			int k = cnt[i] / 2;
			while(k--){
				ret = char (i) + ret;
				ret += char (i); 
			}
		} 
	} 
	
	// output 
	if (odd) ret.insert(ret.begin() + ret.size()/2, char (odd));
	cout << ret<<"\n";
	
	return 0; 
} 
