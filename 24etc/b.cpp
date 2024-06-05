/*
����� : N<=10, type(S)<=10, len(S)<=8/ �ܾ��� ���� �ִ�
�м� : 	���� �ڸ����� ���� ���� ���� ������ �� �ֵ���
		�ڸ����� ���ٸ�, �� ������ ���� ���� ���� ��
		�Ѵ� ���ٸ�, �Ʒ��� �ڸ��� ���켭 ���� ��Ģ ���� 
�ڷᱸ��1 :
	- �ڸ��� ���� �ε��� ���� �� char2index
	- ���ĺ� ���� �ڸ����� ī���� ���� 
���̵�� : ���� ���� �ǵ��� ����, ������ ���� ����, �� �ջ�
	1. ���� ���� �ǵ��� ���� ( ī������ ���� �����ϵ��� ����!) 
	- char2index�� ������� char�� �����Ѵ�.
		1. ���� �ڸ����� Ȯ���ؼ� �� ���� ī������ ��� ũ��
		2. 1���� ���� ���, �� �Ʒ� �ڸ����� �Ǻ��Ѵ�.
	2. ������ �� ���� �� �ջ�
		1. for(9���� ����)
			2. ���ĵ� �迭�� char�� ����Ͽ�, ���ڷ� ��ȯ
			3. ret += ��ȯ�� ��
�ð� ���⵵ : N*10 + N*logN * 10 + 10*10 / ��+4��+�� < 2��
�ڷᱸ�� : N, S, c2idx, t[10], cnt[10][10], ret,  
���� : �ڸ��� �ø����ִ� ����, ���� ���� 
��谪 : ���� �ڸ����� ������,
		���ķ����� ������ ��,
		�پ��� ���ĺ�
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
	for(int i=10; i>=0; i--){// ���� �ڸ����� Ȯ�� 
		int _a = cnt[c2idx[a]][i]; 
		int _b = cnt[c2idx[b]][i]; 
		if( _a != _b) return _a > _b; 
		// ������ ���� �ڸ��� Ȯ��  
	} 
	return false; // ������ ���� ��� 
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
 
