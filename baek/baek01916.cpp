#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;
#define INF 2e9

int dept, arrv, n, m, _a, _b, _c;
int dist[1001];
int graph[1001][1001];

void
dijstra()
{
	char visited[1001] = {0};
	int min_val, min_node;
	for(int i = 1; i <= n; i++) dist[i] = INF;
	dist[dept] = 0;
	for(int i = 1; i <= n; i++){
		min_val = INF;
		for(int j = 1; j <= n; j++){
			if(!visited[j] && dist[j] < min_val)
				min_val = dist[j], min_node = j;
		}
		visited[min_node] = 1;
		for(int j = 1; j <= n; j++){
			if(graph[min_node][j] != -1 && dist[min_node] + graph[min_node][j] < dist[j])
				dist[j] = dist[min_node] + graph[min_node][j];
		}
	}
}

int
main()
{
	memset(graph, -1, sizeof(int) * 1001 * 1001);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		if(graph[_a][_b] == -1 || _c < graph[_a][_b]) graph[_a][_b] = _c;
	}
	scanf("%d %d", &dept, &arrv);

	dijstra();
	printf("%d\n", dist[arrv]);
}
