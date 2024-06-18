/*
����� : �ٸ��� �ݺ��Ǵ� ���ڿ� / �յڰ� ������ True 
�м� : ������ �Ǵ� �ؼ� �ش� ���ڿ� ���� ���� ����
	- �����ڵ�����
	- �ƽ�Ű�ڵ� : ����(��ҹ���)����
	- �ƽ�Ű�ڵ� : Ư����ȣ����
���̵��
	- ���ѹݺ�
		- if(���̶� �ڶ� ���� �ε����� ����ų��) ����
		- if(�����ڵ����� Ȯ��)//�ϴ� utf-8��������  
			- index ���� 
			- if(���̶� �ڶ� ���� �ε����� ����ų��) ����
			- if(�ٸ� �������� Ȯ��) return false; 
		- else if(��������)
			- ��ҹ��� ���� value ����
			- if(�ٸ� �������� Ȯ��) return false; 
		- else 
			- if(�ٸ� �������� Ȯ��) return false;
�ð����⵵ : T*len(s)
�ڷᱸ�� : ret, s 
���� : �ѱ��ζ� ����, �ѱ� ���� ���϶� ����,
		�������� ��ҹ��ڰ� ������ ���ö� ����
		Ư����ȣ ���� ���� �� ����
		�ѱ��� ��� �ڿ��� ���� �ε��� ��Ʋ���°� ����
		���ڵ��� �Ǻ��ؾ��ϳ�(���߿� �ð� �Ǹ�)
		���� ¦���϶��� Ȧ�� �ֶ� ���� 
		out of range ����  
��谪 : �ѱ�/Ư����ȣ/���� ���ΰ� 
		���� ��ҹ��� ���ΰ�  AbbBa 
		�ѱ۸� �ִ°� ������ ���(�� ���)
�׽�Ʈ ���̽�
- input
hello
raccecar
kayak
aa#$4$#aa
1234567
00110101100
AbbBa
AbBbBa
A#b1b1B#a
A#b1b1B!a
�ⷯ��
�丶��
�ⷯ����
���丶��
�ⷯ�䷯��
��a11A��
��a1$��4$1A��
��a1$��4��$1A��
��a1$��44��$1A��
- output
False
False
True 
True
False
True
True
True
True
False
True
True
True
False
True
True
False
False
True 
*/
#include<bits/stdc++.h>
#include<cassert>
using namespace std;
string ret;


void print_s(string s){
	cout << s << " : " ; 
	for(char c : s){
		cout << bitset<8>(c) << " "; 
	}
	cout << endl; 
} 

bool sol(string str){
	int len = str.size();
	int start=0, end=len-1;

	while(start < end){
		unsigned char c = str[start];
		if((str[start] & 0x80) != 0){//�����ڵ� utf-8
			string  start_v, end_v;
			int _byte = 1; 
			
	        if ((c & 0xF0) == 0xF0) _byte = 4;  // 4����Ʈ ����
	        else if ((c & 0xE0) == 0xE0) _byte = 3; // 3����Ʈ ����
			else if ((c & 0xC0) == 0xC0) _byte = 2;  // 2����Ʈ ����

			if( end - _byte < 0 || start+_byte >= len ) return false; // check out of range

			// �ε��� ����
			end -= _byte-1;
			if(start - end == 0) break; // Ȧ�� �� ���

			start_v = str.substr(start, _byte);
			end_v = str.substr(end, _byte);
			if(start_v != end_v) return false;


			
			start += _byte; 
			end--; 
		
		}else if( (c >='A' && c <='Z') ||
				  (c >='a' && c <='z')	 ){// ���� ��ҹ���
			char start_v=str[start], end_v=str[end]; 
			if(str[start] >='a'){//�빮�ڷ� ���� 
				start_v = str[start] - 'a' + 'A'; 
			} 
			if(str[end] >='a'){//�빮�ڷ� ���� 
				end_v = str[end] - 'a' + 'A'; 
			} 
			
			if( start_v != end_v ) return false;
			
			start++;end--; 
		}else{// Ư����ȣ�� 
			if( str[start] != str[end] ) return false;
			start++;end--;
		} 
	} 
	return true; 
} 

int main() {
	// set 
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "������ �� �� �����ϴ�." << endl;
        return 1;
    }
	
	// input 
    string line;
    while (getline(file, line)) {
        // calc and output 
		if(sol(line)) ret += "True\n";
		else  ret += "False\n";
    }
    file.close();
    
    // output 
    cout << ret;

    return 0;
}


 
