#include<bits/stdc++.h>
using namespace std;

vector<int> ret, input;//{20,7,23,19,10,15,25,8,13};
int sum;// =accumulate(input.begin(), input.end(),0); 

int main(){
	//input 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	for(int i=0; i<9; i++){
		int tmp = 0;
		cin >> tmp; 
		input.push_back(tmp); 
		sum += tmp; 
	}  
	
	// calc 
	int max = input.size(); 
	
	sort(input.begin(), input.end()); 
	 
	for(int i=0; i<max-1; i++){
		for(int j=i+1; j<max; j++){
			if( sum - input[i] - input[j] == 100){
			 	 ret.push_back(input[i]);
				 ret.push_back(input[j]);
				 break; 
			} 
		 }
		 if(ret.size()>0) break; 
	} 
	
	// output
	for (int i=0; i<max; i++){
		int tmp = input[i]; 
		if(tmp != ret[0] and tmp != ret[1]) cout<<tmp<<"\n"; 
	} 
} 
