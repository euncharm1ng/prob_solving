#include <stdio.h>
#include <string.h>

#define INF 10e7

int n, m, x, ans = 0;;
int _a, _b, _c;
int graph[1001][1001], reverse_graph[1001][1001];
int dist [1001], reverse_dist[1001];
int visited[1001] = {0}, reverse_visited[1001] = {0};

void
dijstra(int graph[1001][1001], int dist[1001], int visited[1001])
{
	int min, min_vertex;
	for(int i = 1; i <= n; i++) dist[i] = INF;
	dist[x] = 0;
	for(int i = 0; i < n; i++){
		min = INF;
		for(int j = 1; j <= n; j++){
			if(!visited[j] && dist[j] < min)
				min = dist[j], min_vertex = j;
		}
		visited[min_vertex] = 1;
		for(int j = 1; j <= n; j++){
			if(graph[min_vertex][j] != -1 && 
				dist[min_vertex] + graph[min_vertex][j] < dist[j])
				dist[j] = dist[min_vertex] + graph[min_vertex][j];
		}
	}
}

int
main()
{
	memset(graph, -1, sizeof(int) * 1001 * 1001);
	memset(reverse_graph, -1, sizeof(int) * 1001 * 1001);
	scanf("%d %d %d", &n, &m, &x);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		graph[_a][_b] = _c;
		reverse_graph[_b][_a] = _c;
	}
	dijstra(graph, dist, visited);
	dijstra(reverse_graph, reverse_dist, reverse_visited);
	for(int i = 1; i <= n; i++)
		if(dist[i] + reverse_dist[i] > ans) 
			ans = dist[i] + reverse_dist[i];
	printf("%d\n", ans);
}
