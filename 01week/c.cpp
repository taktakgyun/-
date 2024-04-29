#include<bits/stdc++.h>
using namespace std;
int a[101]={0,};
int A,B,C,ret=0;

int main(){
	//input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL); 
	cin >> A>>B>>C; 
	
	// and set data 
	for (int i=0 ; i<3; i++) {
		int t1,t2;
		cin >> t1 >> t2;
		
		for(int t=t1; t<t2; t++){
			a[t] += 1;
		}
	}
	
	// calc
	for(int i : a){
		switch(i){
			case 1:
				ret += A; 
				break;
			case 2:
				ret += 2*B; 
				break; 
			case 3:
				ret += 3*C; 
				break; 
		}
	}
	cout<<ret<<"\n"; 
} 
