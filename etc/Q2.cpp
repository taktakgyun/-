/*
����� : �α� ���� 
�̼� :
	- �α� ������ ������ �����ϱ�  
	- A : # ������ �����ϰ� �����ϱ�
	- ���� �޸��� ����, ������ �� �޸��� �ٸ��ɷ� ���� 
	- B : �޸��� ������(�����ϱ�)
	
����Ʈ �����ϱ� 
�ؼ� : �ٴ����� �ؼ��Ѵ�.
	# �� ������ �׳� ����Ѵ�. 
���̵�� : �ٴ����� �ؼ��ؼ� �Ǻ��Ѵ�. 
	1. �ݺ�(��� ��)
		2. �ݺ�(��� ����)
			3. if(���� ������) �� �����ؼ� ����Ѵ�.
			4. if(,�� ������) comma(# )�� �����ؼ� ����Ѵ�.
�ð����⵵ : len(s) 
���� : �߰��߰��� �޸��� �� �ִ�.
		`/t` ���ڰ� �� �ִ�.
*/
#include<bits/stdc++.h>
using namespace std;

string change_tab_to_comma(const string &line){
	// ���� : "tab" -> "," 
	// ���� : "," -> "# "
	string ret;
	 
	for(char c : line){
		if(c=='\t') ret += ',';
		else if(c==',') ret += "# ";
		else ret += c; 
	}
	return ret; 
	
	
	
}
string change_comma_to_tab(const string &line){
	// ���� : "," -> "tab" 
	// ���� : "# " -> ","
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
