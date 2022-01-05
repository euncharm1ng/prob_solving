#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int n, _a, _b, _c, max_len = 0, next_start;
vector<pii> tree[10001];
int visited[10001] = {0};

int
dfs(int curr, int dist)
{
	int ret = dist;
	visited[curr] = 1;
	if(dist > max_len){
		next_start = curr;
		max_len = dist;
	}
	for(int i = 0; i < tree[curr].size(); i++){
		if(!visited[tree[curr][i].first]){
			int temp = dfs(tree[curr][i].first, dist+tree[curr][i].second);
			if(temp > ret) ret = temp;
		}
	}
	return ret;
}

int 
main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		tree[_a].push_back({_b, _c});
		tree[_b].push_back({_a, _c});
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(int) * 10001);
	printf("%d\n", dfs(next_start, 0));
}
