/*
입출력 : 로그 파일 
미션 :
	- 로그 파일을 수정후 저장하기  
	- A : # 라인은 제거하고 저장하기
	- 탭을 콤마로 변경, 구분자 외 콤마는 다른걸로 변경 
	- B : 콤마를 탭으로(원복하기)
	
디폴트 구현하기 
해석 : 줄단위로 해석한다.
	# 이 있으면 그냥 출력한다. 
아이디어 : 줄단위로 해석해서 판별한다. 
	1. 반복(모든 줄)
		2. 반복(모든 문자)
			3. if(탭이 있으면) 로 변경해서 출력한다.
			4. if(,가 있으면) comma(# )로 변경해서 출력한다.
시간복잡도 : len(s) 
조심 : 중간중간에 콤마가 들어가 있다.
		`/t` 문자가 들어가 있다.
*/
#include<bits/stdc++.h>
using namespace std;

string change_tab_to_comma(const string &line){
	// 변경 : "tab" -> "," 
	// 변경 : "," -> "# "
	string ret;
	 
	for(char c : line){
		if(c=='\t') ret += ',';
		else if(c==',') ret += "# ";
		else ret += c; 
	}
	return ret; 
	
	
	
}
string change_comma_to_tab(const string &line){
	// 변경 : "," -> "tab" 
	// 변경 : "# " -> ","
	string ret;
	size_t len = line.size();
	 
	for(int i=0; i<len; i++){
		char c = line[i]; 
		if(c==',') ret += '\t';
		else if(c=='#' && len-i-1>0 && line[i+1]==' '){//out of range
			ret += ',';
			i++; 
		}    
		else ret += c; 
	}
	return ret; 
} 


int main() {
	
	// default 
	cout << "Start Default and A.\n"; 
	{ 
	    // open 
	    ifstream inputFile("http.log.sample");
	    ofstream outputFile("default_output.log");
	    ofstream outputFile_A("typeA_output.log");
	    if (!inputFile) {
	        cerr << "Error opening input file" << endl;
	        return 1;
	    }
	    if (!outputFile) {
	        cerr << "Error opening output file" << endl;
	        return 1;
	    }
	    if (!outputFile_A) {
	        cerr << "Error opening output file" << endl;
	        return 1;
	    }
	 
		string line;
	    while (getline(inputFile, line)) {// input
	    	string temp = change_tab_to_comma(line); 
	    	 
	    	// calc and output 
	        outputFile << temp << "\n";
	        if( temp[0] != '#' ) outputFile_A << temp << "\n"; // type A 
	    }
		// close 
	    inputFile.close();
	    outputFile.close();
	    outputFile_A.close(); 
    } 
    
	// B 
	cout << "Start B.\n"; 
	{
		// open 
	    ifstream inputFile("default_output.log");
	    ofstream outputFile("typeB_output.log");
	    if (!inputFile) { 
	        cerr << "Error opening input file" << endl;
	        return 1;
	    }
	    if (!outputFile) {
	        cerr << "Error opening output file" << endl;
	        return 1;
	    }
	    
	    string line;
	    while (getline(inputFile, line)) {// input
	    	string temp = change_comma_to_tab(line); 
	    	 
	    	// calc and output 
	        outputFile << temp << "\n";
	    }
		
		// close 
	    inputFile.close();
	    outputFile.close();
	} 
    return 0;
}
