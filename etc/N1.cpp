/*
입출력 : Kn<=100 len(N)<=100 자연수 배열
		앞부터 중복횟수 반환, 없으면 [-1] 반환 
해석 : 반복되는 숫자 세기
아이디어 : 갯수map(N -> num), 순서map(N -> seq) 를 관리한다.
	1. 순서map을 꺼내서 seq가 큰 순으로 정렬한다.
시간복잡도 : N + N + NlogN / 100+700
자료구조 : arr, Cnt, Seq, ret 
조심 : 없는 경우
		엄청 많은 경우
		순서 잘 지킬 것
경계값 : 아무것도 없는 경우 
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
