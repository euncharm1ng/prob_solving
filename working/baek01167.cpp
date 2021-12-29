#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v, _a, _i;
short _b;
vector<pair<int, short> > tree[100001];
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
do_bfs(int curr_node, int from_node)
{
	int edge_cnt = tree[curr_node].size();
	int max1 = 0, max2 = 0, without = 0;
	for(int i = 0; i < edge_cnt; i++){
		if(from_node != tree[curr_node][i].first){
			pair<int, int> res = do_bfs(tree[curr_node][i].first, curr_node);
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

void
my_bfs(int curr_node)
{
	
}

int
main()
{
	memset(visited, false, sizeof(false) * 100001);
	scanf("%d", &v);
	for(int i = 1; i <= v; i++){
		scanf("%d", &_i);
		while(1){
			scanf("%d", &_a);
			if(_a != -1){
				scanf("%hd", &_b);
				tree[_i].push_back(make_pair(_a, _b));
			}
			else break;
		}
	}
	pair<int, int> res = do_bfs(1, -1);
	printf("%d\n", max(res.first, res.second));
}
