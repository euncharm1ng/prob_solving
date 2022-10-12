#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>
#define INF 2e9
#define MAX_V 10001

using namespace std;

int mac_loc[MAX_V], mac_dist[MAX_V], star_loc[MAX_V], star_dist[MAX_V];
int vertex, edge, v1, v2, w, ans = INF;
int mac_cnt, mac_threshold, star_cnt, star_threshold;
vector<pii> graph[MAX_V]; // dest, weight
priority_queue <pii, vector<pii>, greater<pii> > q;


void
dijstra(int store_dist[], int store_loc[], int store_cnt)
{
	for(int i = 1; i <= vertex; i++) store_dist[i] = INF;
	for(int i = 0; i < store_cnt; i++){
		store_dist[store_loc[i]] = 0;
		q.push({0, store_loc[i]});
	}

	while(!q.empty()){
		pii curr = q.top(); q.pop();
		int curr_v = curr.second;
		for(int i = 0; i < graph[curr_v].size(); i++){
			if(store_dist[graph[curr_v][i].first] > store_dist[curr_v] + graph[curr_v][i].second){
				store_dist[graph[curr_v][i].first] = store_dist[curr_v] + graph[curr_v][i].second;
				q.push({store_dist[graph[curr_v][i].first], graph[curr_v][i].first});
			}
		}
	}
}

int
main()
{
	scanf("%d %d", &vertex, &edge);
	for(int i = 0; i < edge; i++){
		scanf("%d %d %d", &v1, &v2, &w);
		graph[v1].push_back({v2, w});
		graph[v2].push_back({v1, w});
	}

	scanf("%d %d", &mac_cnt, &mac_threshold);
	for(int i = 0; i < mac_cnt; i++){
		scanf("%d", &mac_loc[i]);
	}

	scanf("%d %d", &star_cnt, &star_threshold);
	for(int i = 0; i < star_cnt; i++){
		scanf("%d", &star_loc[i]);
	}

	dijstra(mac_dist, mac_loc, mac_cnt);
	dijstra(star_dist, star_loc, star_cnt);

	for(int i = 1; i <= vertex; i++){
		if(mac_dist[i] != 0 && mac_dist[i] <= mac_threshold 
			&& star_dist[i] != 0 && star_dist[i] <= star_threshold 
			&& mac_dist[i] + star_dist[i] < ans)
				ans = mac_dist[i] + star_dist[i];
	}
	if(ans == INF) puts("-1");
	else printf("%d\n", ans);
}
