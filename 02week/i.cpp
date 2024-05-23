/*
���� : N<=100, len(s)<=100, �ҹ��� ���� / ���� ���ڸ� ������ ������ ���پ�
idea : ���ڿ��� �����鼭 ���ڸ� �Ľ��ϰ� �Ѵ�. �׸��� �켱���� ť�� �ִ´�.
	0. ���� ��� ���ڿ��� ��� �ڷ�,  ������ �պ��� ��  
	1. ���ڸ� �ϳ��� ������ ���ڸ� �װ�,
		���ڸ� ���±��� �ִ��� �պ��� 0 �ǵ� ���� ����,
			�켱���� ť �ױ�, ���� �ʱ�ȭ 
�ð� ���⵵ : 2*N*len(s) + (5000)*log(5000) /2��+10�� < 1��
�ڷᱸ�� : N, s, ret, temp, 
 
���� : �տ� 0�� ���� �ڸ� ����, 0�� �ܵ��̸� 0���, ���� �� �� ���
	temp �ʱ�ȭ  
��谪 : �ڸ����� 100�ڸ��� �� ���, �����Ŵ� ����  
	�տ� 0�� �� ���ڵ�, 
	���� ���� �ִ� ���, 0�� �ִ°�, 
	��û ��� , 
	�������� ����  
*/

#include<bits/stdc++.h>
using namespace std;
int N;
string s, temp; 
vector<string> ret;
bool cmp(string a, string b){
	if(a.size() == b.size()) return a<b; 
	return a.size() < b.size(); 
} 

//bool cmp(string a, string b){
//	if(a.size() == b.size()){
//		int s = a.size(); 
//		for(int i=0; i<s; i++){
//			if(a[i] < b[i]) return true; 
//		} 
//		return false; 
//	}
//	return  a.size() < b.size(); 
//}  

string get_num(string t){
	int i=t.size()-1; 
	int cur = 0;
	for(;cur<i;cur++){// �տ� 0����  
		if(t[cur] != '0') break; 
	}
	if(cur>0) t.erase(0, cur);
	return t;
} 

int main(){
	// inupt
	cin >> N;
	while(N--){
		//init
		temp="";
		
		 // input  
		cin >> s;
		
		// calc 
		for(char a :s){
			if(a>='0' && a<='9'){// nuber? 
				temp += a; 
			}else if(temp.size()){//alpabat?
				ret.push_back(get_num(temp)); 
				temp = ""; 
			} 
		} 
		
		// ���ٰ� ������ ���� ����
		if(temp.size()){// ������ 
			ret.push_back(get_num(temp)); 
		} 
	}
	
	sort(ret.begin(), ret.end(), cmp); 
	
	// output
	for(auto a: ret){
		cout << a << "\n"; 
	} 
	return 0; 
} 
