// 10 >= N > M > 1/ J<=20  / N ��ũ�� M �ٱ��� / �̵��Ÿ� �ּ�
// idea : �Ÿ�����, �ٱ��� �����ؼ� ��ġ ���� ���Ѵ�. (�׸��� �˰���) 
// ���� : ���� ��ġ�� ���� ��ġ ������(�ٱ��� ����)
// 1. �ݺ��� -��� ��ġ(��� ����� ����Ʈ����)
// 2. 	if (��� ��ġ > �� ��ġ) move = max(�����ġ - ����ġ - �ٱ��� ũ��, 0)
// 3.	else(�����̶��) move = �� ��ġ - �����ġ
// 4. 	ret += abs(move) / �� ��ġ += move 
// �ð� ���⵵ : J / 20< 1�� 
// �ڷᱸ�� : N, M, J, move, ret, cur 
// ���� : �ٱ��� ���̿� ���� �ٸ� ���꿡 ���� 

#include<bits/stdc++.h>
using namespace std;
int N, M, J, t, mv, ret, cur=1;

int main(){
	// input
	cin >> N >> M >> J;
	M--; 
	while(J--){
		// input
		cin >> t;
		
		// calc 
		if(t > cur) mv = max(t - cur - M, 0);
		else  mv = t - cur;
		
		ret += abs(mv);
		cur += mv; 
	}
	cout << ret << "\n"; 
} 
 
