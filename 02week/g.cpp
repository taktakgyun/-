// N<=1000 C<1_000_000_000 1��
// ���� �����ϴ°� ������������ �׸���� ���� ������  
// idea : Ƚ���� ������ �����ϰ�, list ������ Ƚ�� ū�� ��� 
// 1. �ڷ� ����map���� ���� ī����, 1�̸� list�� �ֱ�(���� ���� ����) 
// 2. list ������� ��ȸ ���� cnt ū�� ����ϰ� �װ� ���� 
// �ð����⵵ : NN / 1_000_000 < 1��  
// �ڷᱸ�� : N, C, mp<int, cnt>, list a<int>, a_size 
// ��谪 :  ��� ���� ��, N=1, ��� ���� ����  

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

