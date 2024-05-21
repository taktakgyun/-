// N<=1000 C<1_000_000_000 1�� / ���� �����ϴ°� ������������
// idea : ��ųʸ��� �󵵰��, ret�� ��� ������� ����
// 1. ��ųʸ��� ����
// 2. �켱����ť�� ����Ѵ�. �ϰ� ���
// �ð����⵵ : 2N?
// �ڷᱸ�� : N, C, dict(int,num), qe<int,num>

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
