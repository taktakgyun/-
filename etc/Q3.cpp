/*
����� : �� ����
�ؼ� : 1�� ���Ͽ��� 1�ܾ�, 2�� ���Ͽ��� 1�ܾ� ������׷� ���
		�ܾ� ���� ���� space �߰� ��, ���࿡���� ����
���̵�� :
	�Է� file1->que1 file2->que2 / ���� file�� ���� �� "##endend"�� �־��ش�. 
	��� que1,que2�� 1�� �̻� ���� �� ����
	���� �������� : ������ "##endend" �� ������,
					�ٸ��ʵ� "##endend" ���ö� ���� ����   
	1. input_strame(�����̸�, ��ǥ que)
		2. �ݺ�( ��� ���� ���� ������) ���� que�� ������. 
		3. que�� "##endend"�̰� ������. 
		4. �������ϰ� ����
	
	1. output_strame(Ʃ�� que)
		��� que 
		2. �ݺ�(���ѹݺ�)
			3. if(�������� que�� �ϳ��� 0�̸�) �� sleep
			4. Ʃ�� s = que.top(); que.pop();
			5. for( Ʃ�� �������)
					if ("##endend")
						for(�ٸ� ģ�� "##endend" �̰� ���ö�����)
							if(�ٸ� ģ�� size==0�̸�) ��� ���� 
							��� que. push 
						output_que(��� que)
						����  
			
	1. output_que(que)
		2. �ݺ�( que ������������)
			��� 
			if( ����ƴϸ� )  space �߰� 
�ð����⵵ : 2*len(f1.line) + 2*len(f2.line) /
			if(f1==f2) 4*len(line) < 1�� / len(line) < 250���� 		 
�ڷᱸ�� : input_que_list[2] 
���� : ���࿡�� ���� ����
		���� ��� "##endend"�� ���ÿ� ������ ��� 
		���� �ݴ°�
��谪 :  
		������ ���� �������� ���  
		������ �ƹ� �Էµ� ���� ��
		������ ��� ���ุ ���� ��
		�������� ������ ���� 
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
        	if(line.size()){ // ù��° �����̸� ������ �Ѵ�.
        	
	            input_que.push(line);
	            line.clear();
			} else {
				input_que.push("\n");
			} 
        } else {
            line += character;
        }
    }
    
    // input - ������  
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
		for(int i : target){// ������ �������� ���ư��鼭 ��� 
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
