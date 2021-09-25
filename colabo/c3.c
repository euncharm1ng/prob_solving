#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int p, q, r, n, m, **graph, **distance;

int
main()
{
	int a, b;
	scanf("%d %d %d %d %d", &p, &q, &r, &n, &m); // n cities, m lines
	graph = (int**)malloc(sizeof(int*) * (n + 1));
	distance = (int**)malloc(sizeof(int*) * (n+1));
	for(int i = 0; i < n + 1; i++){
		graph[i] = (int*)malloc(sizeof(int) * (n + 1));
		distance[i] = (int*)malloc(sizeof(int) * 3);
		memset(graph[i], 0, sizeof(int) * (n + 1));
		memset(distance[i], -1, sizeof(int) * 3);
	}
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][++graph[a][0]] = b;
		graph[b][++graph[b][0]] = a;
	}

	

	for(int i = 0; i < n + 1; i++){
		printf("%d- ", i);
		for(int j = 0; j < n + 1; j++){
			printf("%d ", graph[i][j]);
		}
		puts("");
		printf("distance: %d %d %d\n", distance[i][0], distance[i][1], distance[i][2]);
	}

}
