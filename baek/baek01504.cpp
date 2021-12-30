#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 1e9


int n, e, _a, _b, _c, v1, v2;
int graph[801][801];
int dist[801] = {0}, dist_v2[801] = {0}, dist_v1[801] = {0};

void 
dijstra(int start, int dist[801])
{
	int visited[801] = {0};
	dist[start] = 0;
	for(int i = 0; i < n; i++){
		int min, min_val = INF;
		for(int j = 1; j <= n; j++){
			if(!visited[j] && dist[j] != -1 && dist[j] < min_val){
				min_val = dist[j];
				min = j;
			}
		}
		visited[min] = 1;
		for(int j = 1; j <=n; j++){
			if(graph[min][j] != -1 && (dist[j] == -1 || dist[j] > graph[min][j] + dist[min]))
				dist[j] = graph[min][j] + dist[min];
		}
	}
}

int 
main()
{
	memset(graph, -1, sizeof(int) * 801 * 801);
	memset(dist, -1, sizeof(int) * 801);
	memset(dist_v2, -1, sizeof(int) * 801);
	memset(dist_v1, -1, sizeof(int) * 801);
	scanf("%d %d", &n, &e);
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		graph[_a][_b] = _c;
		graph[_b][_a] = _c;
	}
	scanf("%d %d", &v1, &v2);

	dijstra(1, dist);
	dijstra(v1, dist_v1);
	dijstra(v2, dist_v2);

	if(dist[v1] == -1 || dist[v2] == -1 || dist[n] == -1) puts("-1");
	else printf("%d\n", min(dist[v1] + dist_v2[v1] + dist_v2[n], dist[v2] + dist_v1[v2] + dist_v1[n]));
}
