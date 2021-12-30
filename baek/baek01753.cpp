#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 2e9
typedef pair<int, int> pii;

vector<pii> graph[20001];
priority_queue<pii, vector<pii>, greater<pii> > q;
int v, e, start, _a, _b, _c;
int dist[20001], visited[20001] = {0};

void 
dijstra()
{
	int min_ver, min_val, size, curr_ver, curr_dist;
	dist[start] = 0;
	q.push({0, start});
	while(!q.empty()){
		pii top = q.top();
		q.pop();
		min_val = top.first;
		min_ver = top.second;
		
		size = graph[min_ver].size();
		for(int i = 0; i < size; i++){
			curr_ver = graph[min_ver][i].first;
			curr_dist = graph[min_ver][i].second;
			if(dist[curr_ver] > dist[min_ver] + curr_dist){
				dist[curr_ver] = dist[min_ver] + curr_dist;
				q.push({dist[curr_ver], curr_ver});
			}
		}
	}
}
int 
main()
{
	for(int i = 0; i < 20001; i++) dist[i] = INF;
	scanf("%d %d %d", &v, &e, &start);
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		graph[_a].push_back({_b, _c});
	}

	dijstra();

	for(int i = 1; i <= v; i++){
		if(dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}
