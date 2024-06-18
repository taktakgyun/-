/*
입출력 : 줄마다 반복되는 문자열 / 앞뒤가 같으면 True 
분석 : 범위를 판단 해서 해당 문자에 따른 조건 대입
	- 유니코드인지
	- 아스키코드 : 영문(대소문자)인지
	- 아스키코드 : 특수기호인지
아이디어
	- 무한반복
		- if(앞이랑 뒤랑 같은 인덱스를 가르킬때) 종료
		- if(유니코드인지 확인)//일단 utf-8기준으로  
			- index 보정 
			- if(앞이랑 뒤랑 같은 인덱스를 가르킬때) 종료
			- if(다른 문자인지 확인) return false; 
		- else if(영문인지)
			- 대소문자 빼서 value 보정
			- if(다른 문자인지 확인) return false; 
		- else 
			- if(다른 문자인지 확인) return false;
시간복잡도 : T*len(s)
자료구조 : ret, s 
조심 : 한글인때 조심, 한글 영어 섞일때 조심,
		영문에서 대소문자가 섞여서 나올때 조심
		특수기호 섞여 나올 때 조심
		한글인 경우 뒤에서 갈때 인덱스 뒤틀리는거 조심
		인코딩도 판별해야하나(나중에 시간 되면)
		답이 짝수일때와 홀수 있때 조심 
		out of range 조심  
경계값 : 한글/특수기호/영문 섞인거 
		영문 대소문제 섞인거  AbbBa 
		한글만 있는거 거짓인 답안(좀 긴거)
테스트 케이스
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
기러기
토마토
기러러기
토토마토
기러토러기
기a11A기
기a1$러4$1A기
기a1$러4기$1A기
기a1$러44러$1A기
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
		if((str[start] & 0x80) != 0){//유니코드 utf-8
			string  start_v, end_v;
			int _byte = 1; 
			
	        if ((c & 0xF0) == 0xF0) _byte = 4;  // 4바이트 문자
	        else if ((c & 0xE0) == 0xE0) _byte = 3; // 3바이트 문자
			else if ((c & 0xC0) == 0xC0) _byte = 2;  // 2바이트 문자

			if( end - _byte < 0 || start+_byte >= len ) return false; // check out of range

			// 인덱스 보정
			end -= _byte-1;
			if(start - end == 0) break; // 홀수 일 경우

			start_v = str.substr(start, _byte);
			end_v = str.substr(end, _byte);
			if(start_v != end_v) return false;


			
			start += _byte; 
			end--; 
		
		}else if( (c >='A' && c <='Z') ||
				  (c >='a' && c <='z')	 ){// 영문 대소문자
			char start_v=str[start], end_v=str[end]; 
			if(str[start] >='a'){//대문자로 고정 
				start_v = str[start] - 'a' + 'A'; 
			} 
			if(str[end] >='a'){//대문자로 고정 
				end_v = str[end] - 'a' + 'A'; 
			} 
			
			if( start_v != end_v ) return false;
			
			start++;end--; 
		}else{// 특수기호들 
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
        cerr << "파일을 열 수 없습니다." << endl;
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


 
