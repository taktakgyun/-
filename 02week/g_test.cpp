#include<bits/stdc++.h>
using namespace std;

int main(){
	list<int> a={1,2,3,4,5};
	for(auto it = a.begin(); it != a.end(); it++) cout << *it << endl;
	auto cur = a.begin(); cur++;cur++;
	a.erase(cur); cout<< "del : 3" <<endl;
	for(auto it = a.begin(); it != a.end(); it++) cout << *it << endl;
}
