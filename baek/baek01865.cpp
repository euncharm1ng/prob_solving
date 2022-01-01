#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
#define INF 2e9
typedef pair<int, int> pii;

int f, n, m, w, s, e, t;
int dist[501], ans[4] = {0};

int
bellman_ford(vector<pii> graph[501])
{
	for(int i = 1; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= n; j++){
			//if(dist[j] == INF) continue;
			for(int k = 0; k < graph[j].size(); k++){
				if(dist[j] + graph[j][k].second < dist[graph[j][k].first])
					dist[graph[j][k].first] = dist[j] + graph[j][k].second;
			}
		}
	}
	for(int j = 1; j <= n; j++){
		//if(dist[j] == INF) continue;
		for(int k = 0; k < graph[j].size(); k++){
			if(dist[j] + graph[j][k].second < dist[graph[j][k].first])
				return 1;
		}
	}
	return 0;
}

int 
main()
{
	scanf("%d", &f);
	for(int i = 0; i < f; i++){
		scanf("%d %d %d", &n, &m, &w);
		vector<pii> graph[501];
		for(int j = 0; j < m; j++){
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back(make_pair(e, t));
			graph[e].push_back(make_pair(s, t));
		}
		for(int j = 0; j < w; j++){
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back(make_pair(e, -t));
		}
		if(bellman_ford(graph)) ans[i] = 1;
	}
	for(int i = 0; i < f; i++){
		if(ans[i] == 1) puts("YES");
		else puts("NO");
	}
	return 0;
}
