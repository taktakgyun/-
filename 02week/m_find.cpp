#include<bits/stdc++.h>
using namespace std;

int main(){
	string s = "123351238845732666612314";
	cout << s.find("6666") << endl; // 16 //index
	cout << (s.find("123123") == string::npos)<<endl; // true
} 
