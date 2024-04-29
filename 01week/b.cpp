#include<bits/stdc++.h>
using namespace std;
int ret[129]={0, };
int b=int('a'), e=int('z');
string a;
 
int main(){
	//input
	cin>>a;
	
	//calc
	for(char c:a){
		ret[int(c)] += 1;
	}
	
	//output
	for(int i=b; i<=e; i++){
		cout<<ret[i] << " ";
	}
	cout<<"\n";
} 
