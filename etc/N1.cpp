/*
����� : Kn<=100 len(N)<=100 �ڿ��� �迭
		�պ��� �ߺ�Ƚ�� ��ȯ, ������ [-1] ��ȯ 
�ؼ� : �ݺ��Ǵ� ���� ����
���̵�� : ����map(N -> num), ����map(N -> seq) �� �����Ѵ�.
	1. ����map�� ������ seq�� ū ������ �����Ѵ�.
�ð����⵵ : N + N + NlogN / 100+700
�ڷᱸ�� : arr, Cnt, Seq, ret 
���� : ���� ���
		��û ���� ���
		���� �� ��ų ��
��谪 : �ƹ��͵� ���� ��� 
*/ 
#include<bits/stdc++.h>
using namespace std;
int arr[] = {3,5,7,9,1}; 
//3,2,4,4,2,5,2,5,5};
//1, 2, 3, 3, 3, 3, 4, 4};
map<int, int> Cnt, Seq;
vector<int> sorted_seq;

bool cmp(int a, int b){
	return Seq[a] < Seq[b]; 
}
void print_v(vector<int> vec){
	for(int i : vec){
		cout << i << " "; 
	} 
	cout << "\n"; 
}
void print_m(map<int, int> mp){
	for(auto i : mp){
		cout << i.first << "/" << i.second << " "; 
	} 
	cout << "\n"; 
} 
int main(){
	// set 
	int _size =  (sizeof(arr) / sizeof(int));
	for(int i = _size-1; i>=0; i--){
		Cnt[arr[i]]++;
		if(Cnt[arr[i]] > 1) {
			Seq[arr[i]] = i;	 
		}
	}
	// calc
	for(auto i : Seq){
		sorted_seq.push_back(i.first); 
	}
	if(sorted_seq.size()){
		sort(sorted_seq.begin(), sorted_seq.end(), cmp);
print_v( sorted_seq); 
		// output
		for(int i :sorted_seq){
			cout << Cnt[i] << " "; 
		} 
		cout << "\n"; 
	} 
	else cout << "-1\n"; 
	
	return 0; 
}
