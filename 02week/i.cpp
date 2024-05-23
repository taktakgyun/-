/*
입출 : N<=100, len(s)<=100, 소문자 숫자 / 나온 숫자를 작은거 순으로 한줄씩
idea : 문자열을 읽으면서 숫자만 파싱하고 한다. 그리고 우선순위 큐에 넣는다.
	0. 정렬 방식 문자열이 길면 뒤로,  같으면 앞부터 비교  
	1. 문자를 하나씩 꺼내서 숫자면 쌓고,
		문자면 여태까지 있던거 앞부터 0 맨뒤 빼고 삭제,
			우선순위 큐 쌓기, 문자 초기화 
시간 복잡도 : 2*N*len(s) + (5000)*log(5000) /2만+10만 < 1억
자료구조 : N, s, ret, temp, 
 
조심 : 앞에 0이 들어가면 뒤만 가능, 0만 단독이면 0출력, 같은 수 다 출력
	temp 초기화  
경계값 : 자리수가 100자리수 인 경우, 같은거는 제거  
	앞에 0이 들어간 숫자들, 
	같은 숫자 있는 경우, 0만 있는거, 
	엄청 긴거 , 
	마지막이 숫자  
*/

#include<bits/stdc++.h>
using namespace std;
int N;
string s, temp; 
vector<string> ret;
bool cmp(string a, string b){
	if(a.size() == b.size()) return a<b; 
	return a.size() < b.size(); 
} 

//bool cmp(string a, string b){
//	if(a.size() == b.size()){
//		int s = a.size(); 
//		for(int i=0; i<s; i++){
//			if(a[i] < b[i]) return true; 
//		} 
//		return false; 
//	}
//	return  a.size() < b.size(); 
//}  

string get_num(string t){
	int i=t.size()-1; 
	int cur = 0;
	for(;cur<i;cur++){// 앞에 0제거  
		if(t[cur] != '0') break; 
	}
	if(cur>0) t.erase(0, cur);
	return t;
} 

int main(){
	// inupt
	cin >> N;
	while(N--){
		//init
		temp="";
		
		 // input  
		cin >> s;
		
		// calc 
		for(char a :s){
			if(a>='0' && a<='9'){// nuber? 
				temp += a; 
			}else if(temp.size()){//alpabat?
				ret.push_back(get_num(temp)); 
				temp = ""; 
			} 
		} 
		
		// 끝다고 마지막 숫자 판정
		if(temp.size()){// 있으면 
			ret.push_back(get_num(temp)); 
		} 
	}
	
	sort(ret.begin(), ret.end(), cmp); 
	
	// output
	for(auto a: ret){
		cout << a << "\n"; 
	} 
	return 0; 
} 
