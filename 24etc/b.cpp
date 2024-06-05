/*
입출력 : N<=10, type(S)<=10, len(S)<=8/ 단어의 합의 최댓값
분석 : 	높은 자릿수의 수가 높은 수를 가져갈 수 있도록
		자릿수가 같다면, 더 개수가 많은 것이 높은 수
		둘다 같다면, 아래의 자리도 살펴서 위에 규칙 적용 
자료구조1 :
	- 자릿수 별로 인덱스 적용 맵 char2index
	- 알파벳 마다 자릿수별 카운팅 적용 
아이디어 : 높은 수가 되도록 선정, 선정된 수로 변경, 수 합산
	1. 높은 수가 되도록 선정 ( 카운팅을 보고 정렬하도록 하자!) 
	- char2index를 기반으로 char을 정렬한다.
		1. 높은 자리별로 확인해서 더 높은 카운팅인 경우 크다
		2. 1번이 같을 경우, 그 아래 자리에서 판별한다.
	2. 선정된 수 변경 및 합산
		1. for(9부터 역순)
			2. 정렬된 배열에 char을 사용하여, 숫자로 변환
			3. ret += 변환된 수
시간 복잡도 : N*10 + N*logN * 10 + 10*10 / 백+4백+백 < 2억
자료구조 : N, S, c2idx, t[10], cnt[10][10], ret,  
조심 : 자릿수 올림해주는 로직, 정렬 로직 
경계값 : 같은 자릿수가 여러개,
		정렬로직이 복잡한 것,
		다양한 알파벳
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int N, cnt[11][11];
ll ret; 
vector<char> ty;
map<char,int> c2idx;
string s;

bool cmp(char a, char b){
	for(int i=10; i>=0; i--){// 높은 자리부터 확인 
		int _a = cnt[c2idx[a]][i]; 
		int _b = cnt[c2idx[b]][i]; 
		if( _a != _b) return _a > _b; 
		// 같으면 다음 자릿수 확인  
	} 
	return false; // 완전히 같을 경우 
} 
void print_cnt(){
	for(char c : ty){
		cout << c<< " : ";
		for(int i=0; i<11; i++)
			cout <<  cnt[c2idx[c]][i] << " ";
		cout << "\n"; 
	} 
} 

int main(){
	// input
	cin >> N;
	
	int index=1; 
	while(N--){
		// input
		cin >> s;
		int i=s.size()-1, d=0; 
		for(; i>=0; i--, d++){
			char c=s[i];
			if(c2idx[c] == 0){
				c2idx[c] = index++;
				ty.push_back(c); 
			}
			cnt[c2idx[c]][d]++;			
		}
	}
	// set	
	for(char c: ty){
		for(int i=0; i<10; i++){
			cnt[c2idx[c]][i+1] += cnt[c2idx[c]][i] / 10;
			cnt[c2idx[c]][i] = cnt[c2idx[c]][i] % 10; 
		} 
	} 
	// calc
	sort(ty.begin(), ty.end(), cmp);
	 
	
	int num = 9; 
	for(char c: ty){
		ll temp = 0;
		
		for(int i=10; i>=0; i--){
			temp *= 10; 
			temp += cnt[c2idx[c]][i]*num; 
		}
		ret += temp;
		num--; 
	}
	
	// output
	cout << ret << "\n";
	return 0; 	
} 
 
