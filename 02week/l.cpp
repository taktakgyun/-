/*
입출력 : N<=100 T(1,2) MM:SS 0<=MM<=47  00<=SS<=59  / 1번 MM:SS 2번 MM:SS
해석 : 시간동안 얼마나 이기고 있는지를 판단해야한다. 3천개정도 배열 만들자!
idea : 점수를 배열에 기록해 두자! 그래서 배열을 시간을 계산하자
		분을 모두 초로 계산한다.
1. 시간을 초로 해석해서 해당 초부터 48분 전 지점까지 1로 만든다 
2. 나중에 하나씩 비교해서 한쪽이 크면 카운팅을 한다. 
시간복잡도 : 시간 * N / 3천 * 백 = 10만 < 1억  
자료구조 : N, cnt1, cnt2, mm, ss, score[2][3000]
조심 : 48분은 없다! 47분 59초 까지만 있다.  
경계값 : N이 100일때 초반에 몰린 것, 뛰에 몰린것,
		한골인데, 마지막에 하나있는 것  
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
