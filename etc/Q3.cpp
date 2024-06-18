/*
입출력 : 두 파일
해석 : 1번 파일에서 1단어, 2번 파일에서 1단어 지그재그로 출력
		단어 변경 마다 space 추가 단, 개행에서는 제외
아이디어 :
	입력 file1->que1 file2->que2 / 종료 file이 끝날 시 "##endend"를 넣어준다. 
	출력 que1,que2에 1개 이상 있을 때 실행
	한쪽 빨리끝남 : 한쪽이 "##endend" 가 들어오면,
					다른쪽도 "##endend" 나올때 까지 실행   
	1. input_strame(파일이름, 목표 que)
		2. 반복( 모든 줄을 읽을 때까지) 값을 que로 던진다. 
		3. que에 "##endend"이거 던진다. 
		4. 마무리하고 종료
	
	1. output_strame(튜플 que)
		출력 que 
		2. 반복(무한반복)
			3. if(실행조건 que가 하나라도 0이면) 좀 sleep
			4. 튜플 s = que.top(); que.pop();
			5. for( 튜플 순서대로)
					if ("##endend")
						for(다른 친구 "##endend" 이거 나올때까지)
							if(다른 친구 size==0이면) 잠시 쉬어 
							출력 que. push 
						output_que(출력 que)
						종료  
			
	1. output_que(que)
		2. 반복( que 떨어질때까지)
			출력 
			if( 개행아니면 )  space 추가 
시간복잡도 : 2*len(f1.line) + 2*len(f2.line) /
			if(f1==f2) 4*len(line) < 1억 / len(line) < 250만줄 		 
자료구조 : input_que_list[2] 
조심 : 개행에서 띄어쓰기 조심
		정상 경우 "##endend"가 동시에 나오는 경우 
		파일 닫는거
경계값 :  
		한쪽이 빨리 떨어지는 경우  
		한쪽이 아무 입력도 없을 때
		한쪽이 모두 개행만 있을 때
		마지막이 개행인 파일 
*/ 
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
const string END = "##endend #"; 
queue<string> input_que_list[2];


string consume_and_convert_output_que(queue<string> &que){
	string ret;
	char delimeter=0;
	string temp; 
	while(que.size()){
		temp = que.front(); que.pop();
		
		if(temp == "\n")	delimeter = 0;
		else{
			if(delimeter)  ret += delimeter;
			delimeter =' ';
		} 
		
		ret += temp;
	} 
	return ret; 
} 

void product_input_que(string fname, queue<string> &input_que){
//	cout << "START product_input_que : "<< fname << "\n"; 
	// open 
	ifstream inputFile(fname);
	if (!inputFile) {
		cout << "Error opening input file" << endl;
        cerr << "Error opening input file" << endl;
        exit(1);
        return; 
    } 
    
    // input
    bool flag = false; 
    char character;
    string line;
    while (inputFile.get(character)) {
        if (character == '\n') {
        	if(line.size()){ // 첫번째 개행이면 마무리 한다.
        	
	            input_que.push(line);
	            line.clear();
			} else {
				input_que.push("\n");
			} 
        } else {
            line += character;
        }
    }
    
    // input - 나머지  
    if(line.size()) input_que.push(line);
    else input_que.push("\n");
    
    
    input_que.push(END);
	
	// close 
    inputFile.close();
//    cout << "END product_input_que : "<< fname << "\n"; 
} 



void consume_input_que_and_output_result(string fname){
	
//	cout << "START consume_input_que_and_output_result: "<< fname << "\n"; 
	// open 
    ofstream outputFile(fname);
	if (!outputFile) {
		cout << "Error opening output file" << endl;
        cerr << "Error opening output file" << endl;
        exit(1);
        return;
    }
	
	// calc 
	queue<string> output_que;
	queue<string> *que = input_que_list;
	vector<int> target{0,1};
	string temp;
	char delimeter=0;
	while(target.size()){
		for(int i : target){// 한쪽이 빌때까지 돌아가면서 출력 
			//check que and consume 
			if(input_que_list[i].empty()){
				if(output_que.size()){ 
					temp = consume_and_convert_output_que(output_que); 
					
					if(temp[temp.size()-1] == '\n')	delimeter = 0;
					else{
						if(delimeter)  outputFile << delimeter; 
						delimeter = ' ';
					} 
					
					outputFile << temp; // consume output que
				}
			}
			while(input_que_list[i].empty()) 
				this_thread::sleep_for(chrono::milliseconds(1));
				
			// product output que 
			string temp =  que[i].front(); que[i].pop();
			if(temp == END){// end flag 
				target.erase(remove(target.begin(), target.end(), i), target.end());
			}else{ // nomal input 
				output_que.push(temp); // product output que 
			} 
		} 
	}
	outputFile << consume_and_convert_output_que(output_que); // consume output que 
	
	
	// close 
    outputFile.close();
//	cout << "END consume_input_que_and_output_result: "<< fname << "\n"; 
	return; 
} 

int main(){
	// product 
	thread input1(product_input_que, "file111111.txt", ref(input_que_list[0])); 
    thread input2(product_input_que, "file222222.txt", ref(input_que_list[1])); 
	
	// consume 
	thread output1(consume_input_que_and_output_result, "output.txt");
	
	// end join 
	input1.join();
	input2.join();
    output1.join(); 
    
	cout << "Success\n"; 
	return 0; 
} 
