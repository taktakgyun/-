// N<=1000 C<1_000_000_000 1억
// 많이 등장하는거 오름차순으로 그리고는 등장 순서로  
// idea : 횟수와 순서를 저장하고, list 순서로 횟수 큰거 출력 
// 1. 자료 저장map으로 숫자 카운팅, 1이면 list에 넣기(나온 순서 저장) 
// 2. list 순서대로 조회 가장 cnt 큰거 출력하고 그거 지워 
// 시간복잡도 : NN / 1_000_000 < 1억  
// 자료구조 : N, C, mp<int, cnt>, list a<int>, a_size 
// 경계값 :  모두 같은 수, N=1, 모두 같은 개수  

#include<bits/stdc++.h>
using namespace std;
int N, C, a_size; 
map<int,int> mp;
list<int> a;

int main(){
	// input
	cin >> N >> C;
	
	while(N--){
		int t;
		cin >> t;
		mp[t]++;
		if(mp[t] == 1) {
			a.push_back(t);
			a_size++; 
		} 
	} 
	
	// calc
	while(a_size--){
	 	auto cur_ = a.begin();
	 	auto next_= a.begin();
	 	next_++; 
	 	for(;  next_ != a.end(); next_++){
			 if( mp[*cur_] < mp[*next_] )	cur_=next_; 
		}
		// output
		for(int i=mp[*cur_]; i>0; i--) cout << *cur_ << " ";
		a.erase(cur_); 
	}
	cout << "\n";
	return 0; 
} 

