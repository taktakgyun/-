/*
입출력 : N <= 50, root -1, 각부모노드, 지울 노드번호
		 leef 노드개수
해석 : 노드를 구현한다.
`		리프노드 개수를 구하는 함수를 구한다.
아이디어 : 노드를 백터로 구현하자. 
	세팅. 자식이 부모를 가르킬때마다, 부모에 자식 세팅/ 자식기준도 세팅(그대로 저장)  
	1. 개수 세기
		- 루트 기준으로 시작
		- 자식이 없으면 잎이다.
		1. if( 자식이 없으면) cnt++
		2. else for(모든 자식 순회) 개수세기
	2. 삭제
		- 자식 기준 확인해서 부모기준으로 가서 똑 삭제한다.
시간복잡도 : N + (N-1) + N / 150 < 1억  
자구 : N, ret, tree, A, root, target 
조심 : 루트가 처음이 아닐 때 조심
경계값 : 루트노드 삭제할 경우
		한 노드에 다 붙을 경우 - 다 루트가 삭제되면 다삭제됨
		루트가 리프인 경우 
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
