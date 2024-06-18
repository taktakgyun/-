/*
����� : N <= 50, root -1, ���θ���, ���� ����ȣ
		 leef ��尳��
�ؼ� : ��带 �����Ѵ�.
`		������� ������ ���ϴ� �Լ��� ���Ѵ�.
���̵�� : ��带 ���ͷ� ��������. 
	����. �ڽ��� �θ� ����ų������, �θ� �ڽ� ����/ �ڽı��ص� ����(�״�� ����)  
	1. ���� ����
		- ��Ʈ �������� ����
		- �ڽ��� ������ ���̴�.
		1. if( �ڽ��� ������) cnt++
		2. else for(��� �ڽ� ��ȸ) ��������
	2. ����
		- �ڽ� ���� Ȯ���ؼ� �θ�������� ���� �� �����Ѵ�.
�ð����⵵ : N + (N-1) + N / 150 < 1��  
�ڱ� : N, ret, tree, A, root, target 
���� : ��Ʈ�� ó���� �ƴ� �� ����
��谪 : ��Ʈ��� ������ ���
		�� ��忡 �� ���� ��� - �� ��Ʈ�� �����Ǹ� �ٻ�����
		��Ʈ�� ������ ��� 
*/
#include<bits/stdc++.h>
using namespace std;
int N, ret, A[55], root, target;
vector<int> tree[55];

void print_tree(){
	queue<int> qe;
	qe.push(root);
	while(qe.size()){
		queue<int> temp;
		while( qe.size() ){
			int idx = qe.front();  qe.pop();
			if(idx >= 0){
				cout << idx << " ";
				for(auto i : tree[idx]){
					temp.push(i); 
				}
				temp.push(-1); 
			} 
			else cout << "\t\t"; 
		}
		cout << "\n";
		
		while( temp.size() ){
			int i =  temp.front(); temp.pop(); 
			qe.push(i); 
		} 
	} 
} 

int dfs_cnt(int idx){
	// end
	if(tree[idx].empty()) return 1;
	
	// re
	int cnt=0;
//cout << idx<<")idx: "; 
	for(int i : tree[idx]){
		cnt += dfs_cnt(i);
//cout << cnt << " "; 
	}
//cout << endl; 
	
	return cnt; 
} 

int main(){
	// input
	cin >> N;
	 
	for(int i=0; i<N; i++){
		cin >> A[i];
		if(A[i] == -1) {
			root = i;
		}
		else{
			tree[A[i]].push_back(i); 
		} 
	}
	
	cin >> target;
		
	// calc
	// erase
//for(auto i : tree[A[target]]) cout << i << " ";
//cout << "\n"; 
//cout<<target<<"before\n";print_tree();
	if(target == root){
		cout << 0 << "\n";
		return 0; 
	}else{
		auto it = find(tree[A[target]].begin(), tree[A[target]].end(), target);
		tree[A[target]].erase(it); 
	} 
//	remove(tree[A[target]].begin(), tree[A[target]].end(), target);
//cout<<A[target]<<"after\n";print_tree(); 
	// re
	ret =  dfs_cnt(root); 

	// output
	cout << ret << "\n"; 
	return 0; 
} 
