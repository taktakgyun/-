#include<bits/stdc++.h>
using namespace std;
string s, temp;

int main(){
	cin >> s;
	temp = s;
	reverse(temp.begin(), temp.end());
	if(s==temp) cout<<"1"<<"\n";
	else cout<<"0"<<"\n";
} 



//string in; 
//int main(){
//	//input 
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	
//	cin >> in;
//	
//	//calc
//	int s = in.size();
//	int ss = s/2;
//	bool f = true; 
//	for(int i=0; i<ss; i++){
//		if ( in[i] != in[s-i-1] ){
//			f = false;
//			break; 
//		} 
//	} 
//	if (f){
//		cout<<"1"<<"\n";
//	}
//	else{
//		cout<<"0"<<"\n";
//	}
//} 
