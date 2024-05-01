 #include<bits/stdc++.h>
 using namespace std;
 
 string temp; 
 int N; 
 int cnt[150]={0, };
 vector<char> ret;
  
  
 int main(){
 	//input
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	
	// and count 
	for(int i=0; i<N; i++){
		cin >> temp;
		cnt[int(temp[0])] += 1;
	}
	
	// calc
	int a=int('a'), z=int('z') ; 
	for(int i=a; i<=z; i++){
		if(cnt[i] >=5)	ret.push_back(char(i)); 
	}
	//output 
	if(ret.size() ==0) cout<<"PREDAJA"<<"\n";
	else{
		for(char t:ret){
			cout<<t; 
		} 
		cout<<"\n"; 
	} 
 } 
