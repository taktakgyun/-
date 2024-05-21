// N<=1000 C<1_000_000_000 1억 / 많이 등장하는거 오름차순으로
// idea : 딕셔너리로 빈도계산, ret에 결과 순서대로 저장
// 1. 딕셔너리로 저장
// 2. 우선순위큐를 사용한다. 하고 출력
// 시간복잡도 : 2N?
// 자료구조 : N, C, dict(int,num), qe<int,num>

#include<bits/stdc++.h>
using namespace std;
int N,C, num, v;
map<int, int> mp;

struct cmp{
	bool operator()(pair<int,int> a, pair<int,int> b){ 
		if (a.first < b.first){
			return true; 
		}
		else return false; 
	} 
} ; 

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> qe;

int main(){
	// input
	cin >> N >> C;
	
	while(N--) {
		int temp; 
		cin >> temp;
		mp[temp]++; 
	}
	
	// calc
	for(auto a : mp){
		qe.push({(a).second, (a).first}); 
	}
	
	// output
	while(qe.size()){
		tie(num,v) = qe.top(); qe.pop();
		while(num--) cout << v << " "; 
	} 
	return 0; 
} 
