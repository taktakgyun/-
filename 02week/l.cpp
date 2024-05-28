/*
����� : N<=100 T(1,2) MM:SS 0<=MM<=47  00<=SS<=59  / 1�� MM:SS 2�� MM:SS
�ؼ� : �ð����� �󸶳� �̱�� �ִ����� �Ǵ��ؾ��Ѵ�. 3õ������ �迭 ������!
idea : ������ �迭�� ����� ����! �׷��� �迭�� �ð��� �������
		���� ��� �ʷ� ����Ѵ�.
1. �ð��� �ʷ� �ؼ��ؼ� �ش� �ʺ��� 48�� �� �������� 1�� ����� 
2. ���߿� �ϳ��� ���ؼ� ������ ũ�� ī������ �Ѵ�. 
�ð����⵵ : �ð� * N / 3õ * �� = 10�� < 1��  
�ڷᱸ�� : N, cnt1, cnt2, mm, ss, score[2][3000]
���� : 48���� ����! 47�� 59�� ������ �ִ�.  
��谪 : N�� 100�϶� �ʹݿ� ���� ��, �ٿ� ������,
		�Ѱ��ε�, �������� �ϳ��ִ� ��  
*/
#include<bits/stdc++.h>
using namespace std;
string ret; 
int N, team, cnt1,cnt2, mm,ss, t,score[2][3000];  
const int T = 48*60;

string to_time(int t){
//	string b,f,r  ; 
//	b = to_string((t/60)/10);
//	f = to_string((t/60)%10);
//	r += b+f+":";
//	b = to_string((t%60)/10);
//	f = to_string((t%60)%10);
//	r += b+f;
//	return r; 
    string d = "00" + to_string(t / 60); 
    string e = "00" + to_string(t % 60); 
    return d.substr(d.size() - 2, 2) + ":" + e.substr(e.size() - 2, 2);
} 

int main(){
	// input
	cin >> N;
	while(N--){
		// input
		scanf("%d %2d:%2d", &team, &mm, &ss);
		
		// calc
		t = mm*60 +ss;
		
		// up 
		for(int i=t; i<T; i++) score[team-1][i]++; 
	}
	// calc
	for(int i=0; i<T; i++){
		int a1=score[0][i], a2 =score[1][i]; 
		if( a1 > a2) cnt1++;
		else if(a1 < a2) cnt2++; 
	} 
	// output
	ret += to_time(cnt1)+"\n";
	ret += to_time(cnt2);
	
	cout << ret; 
	return 0; 
} 
