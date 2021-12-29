#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int v, _a, _i, _b, next_start = -1;
vector<pii> tree[100001];
stack<pii> nodes;
bool visited[100001];

void
print_tree()
{
	for(int i = 0; i < v; i++){
		printf("%d ", i);
		for(int j = 0; j < tree[i].size(); j++){
			printf("%d %d ", tree[i][j].first, tree[i][j].second);
		}
		puts("");
	}
}

pair<int, int> // <with, without>
do_dfs(int curr_node, int from_node)
{
	int edge_cnt = tree[curr_node].size();
	int max1 = 0, max2 = 0, without = 0;
	for(int i = 0; i < edge_cnt; i++){
		if(from_node != tree[curr_node][i].first){
			pii res = do_dfs(tree[curr_node][i].first, curr_node);
			int curr_dist = res.first + tree[curr_node][i].second;
			if(curr_dist > max1){
				max2 = max1;
				max1 = curr_dist;
			}
			else if(curr_dist > max2)
				max2 = curr_dist;
			if(res.second > without) 
				without = res.second;
		}
	}
	return make_pair(max1, max(without, max1 + max2));
}

int
my_dfs(int start)
{
	int res = 0;
	memset(visited, false, sizeof(false) * 100001);
	nodes.push({start, 0});
	visited[start] = true;
	while(!nodes.empty()){
		pii curr_pii = nodes.top();
		nodes.pop();
		int curr = curr_pii.first; 
		int dist = curr_pii.second;
		if(dist > res){
			res = dist;
			next_start = curr;
		}
		for(int i = 0; i < tree[curr].size(); i++){
			int next = tree[curr][i].first;
			if(!visited[next]){
				nodes.push({next, dist+tree[curr][i].second});
				visited[next] = true;
			}
		}
	}
	return res;
}

int
main()
{
	scanf("%d", &v);
	for(int i = 1; i <= v; i++){
		scanf("%d", &_i);
		while(1){
			scanf("%d", &_a);
			if(_a != -1){
				scanf("%d", &_b);
				tree[_i].push_back(make_pair(_a, _b));
			}
			else break;
		}
	}
	//pii res = do_dfs(1, -1);
	//printf("%d\n", max(res.first, res.second));
	my_dfs(1);
	printf("%d\n", my_dfs(next_start));
}
