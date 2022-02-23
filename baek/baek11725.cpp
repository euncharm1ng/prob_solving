#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, _a, _b, parent[100001] = {0};
vector<int> tree[100001];
queue<int> Q;

void
find()
{
	int curr;
	parent[1] = 1;
	Q.push(1);
	while(!Q.empty()){
		curr = Q.front(); Q.pop();
		for(auto itr = tree[curr].begin(); itr != tree[curr].end(); itr++){
			if(parent[*itr] == 0){
				parent[*itr] = curr;
				Q.push(*itr);
			}
		}
	}
}

int 
main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &_a, &_b);
		tree[_a].push_back(_b);
		tree[_b].push_back(_a);
	}
	find();
	for(int i = 2; i <= n; i++) printf("%d\n", parent[i]);
}
