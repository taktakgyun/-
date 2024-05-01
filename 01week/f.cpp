#include<bits/stdc++.h>
using namespace std;
string s;

int main(){
	//input
	getline(cin, s);
	
	// calc and output
	for(char c:s){
		if(c>='a' and c<='z'){
			if(c+13>'z') c = c -13;
			else c = c+13; 
		} 
		else if(c>='A' and c<='Z'){
			if(c+13>'Z') c = c -13;
			else c = c+13;
		}
		cout<<c; 
	} 
	cout<<"\n";
	return 0; 
} 


//string s, ret; 
////, ret2;
//
//int main(){
//	// input
//	getline(cin,s); 
//	
//	// calc
//	for(char c: s){
//		if(c>='a' and c<='z') ret.push_back((((c-'a')+13)%26)+'a') ; 
//		else if( c>='A' and c<='Z')ret.push_back((((c-'A')+13)%26)+'A') ; 
//		else ret.push_back(c);
//	}
////	for(char c: ret){
////		if(c>='a' and c<='z') ret2.push_back((((c-'a')+13)%26)+'a') ; 
////		else if( c>='A' and c<='Z')ret2.push_back((((c-'A')+13)%26)+'A') ; 
////		else ret2.push_back(c);
////	}
//	
//	// ouptup
//	 cout << ret << "\n"; 
////	 cout << ret2 << "\n";
//} 
