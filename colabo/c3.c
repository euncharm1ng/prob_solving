#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCITIES 40000
int p, q, r, n, m, **graph, **distance, *city_q, *dist_q;

void
doBFS(int starting_city, int dist_index) // 0:alpha, 1:beta, 2:n
{
	int front = 0, back = 0;
	distance[starting_city][dist_index] = 0;
	for(int i = 1; i <= graph[starting_city][0]; i++){
		//distance[graph[starting_city][i]][dist_index] = 1;
		city_q[back] = graph[starting_city][i];
		dist_q[back++] = 1;
	}
	while(front != back){
		if(distance[city_q[front]][dist_index] > dist_q[front]){
			distance[city_q[front]][dist_index] = dist_q[front];
			for(int i = 1; i <= graph[city_q[front]][0]; i++){
				city_q[back] = graph[city_q[front]][i];
				dist_q[back++] = dist_q[front] + 1;
			}
		}
		front++;
	}
}


int
main()
{
	int a, b;
	long min;
	scanf("%d %d %d %d %d", &p, &q, &r, &n, &m); // n cities, m lines
	graph = (int**)malloc(sizeof(int*) * (n + 1));
	distance = (int**)malloc(sizeof(int*) * (n + 1));
	dist_q = (int*)malloc(sizeof(int) * m * 2);
	city_q = (int*)malloc(sizeof(int) * m * 2);

	for(int i = 0; i < n + 1; i++){
		graph[i] = (int*)malloc(sizeof(int) * (n + 1));
		distance[i] = (int*)malloc(sizeof(int) * 3);
		memset(graph[i], 0, sizeof(int) * (n + 1));
		distance[i][0] = distance[i][1] = distance[i][2] = MAXCITIES;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][++graph[a][0]] = b;
		graph[b][++graph[b][0]] = a;
	}


	doBFS(1, 0);
	doBFS(2, 1);
	doBFS(n, 2);
	/*
	for(int i =0; i < n + 1; i++){
		printf("%d - ", i);
		printf("%d %d %d\n", distance[i][0], distance[i][1], distance[i][2]);
	}
	*/
	long sub_min;
	min = distance[1][0] * p + distance[1][1] * q + distance[1][2] * r;
	for(int i = 2; i <= n; i++){
		sub_min = distance[i][0] * p + distance[i][1] * q + distance[i][2] * r;
		if(min > sub_min)
			min = sub_min;
	}
	printf("%ld\n", min);
/*
	for(int i = 0; i < n + 1; i++){
		printf("%d- ", i);
		for(int j = 0; j < n + 1; j++){
			printf("%d ", graph[i][j]);
		}
		puts("");
		printf("\tdistance %d %d %d \n", distance[i][0], distance[i][1], distance[i][2]);
	}
*/
}


