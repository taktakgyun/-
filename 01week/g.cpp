// ���Ĺ� �������� *�ϳ�/ �߰��� ��ǥ �� ������ ���ĺ� 
// 1. ó���� ���� ������ �ְ�, �߰��� �ƹ��ų� �� �Ǵ°��� �Ǵ�.4
// ���� ��Ȳ : �յ� ������ ���� �Էº��� Ŭ�� � ��Ȳ������ �����̴�. 
#include<bits/stdc++.h>
using namespace std;
int N,idx;
string p, s,b,e, ret=""; 

int main(){
	// input
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	cin >> N; 
	cin >> p;
	idx = p.find('*');
	b = p.substr(0,idx);
	e = p.substr(idx+1); 
	
	// calc
	for(int i=0; i<N; i++){
		// input 
		cin >> s;
		//calc 
		if ( s.size() >= b.size() + e.size()){
			if( s.substr(0, b.size()) == b && s.substr(s.size()-e.size())==e ){
				// output 
				ret += "DA\n"; 
				continue; 
			} 
		}
		ret += "NE\n"; 
	}
	cout << ret; 
	return 0; 
} 


//#include<bits/stdc++.h>
//using namespace std;
//string b,e,s,temp;
//int N,idx;
//
//int main(){
//	// input
////	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
//	cin >> N;
//	cin >> temp;
//	idx = temp.find('*'); 
//	b = temp.substr(0,idx);
//	e = temp.substr(idx+1, temp.size());
//	int bs=b.size(),es=e.size(); 
////	cout <<idx<<" | "<< bs << " : " << b << " : " << es << " : " << e <<endl; 
//	// 
//	for (int i=0; i< N; i++){
//		// input 
//		cin>> s;
//		
//		// calc 
//		int ss = s.size();
//		bool alls =  bs+es > ss;
//		if( alls ) {
//			cout<<"NE\n"; 
//			continue;
//			} 
//		bool b_e = b == s.substr(0,bs);
//		bool e_e = e == s.substr(ss - es, ss); 
//		// output 
//		if (b_e && e_e) cout << "DA\n";
//		else cout<<"NE\n";
//	} 
//	return 0; 
//} 
// 
