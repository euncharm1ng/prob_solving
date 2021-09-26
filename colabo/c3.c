#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXCITIES 40000
int p, q, r, n, m, **graph, **distance, *queue;

void
doBFS()
{
	int start;
	for(int k = 0; k < 3; k++){
		if (k == 0) start = n;
		else start = k;
		int right = 0, left = 0;
		distance[k][start] = 0;
		for(int i = 1; right < graph[start][0]; right++, i++){
			queue[right] = graph[start][i];
			distance[k][queue[right]] = 1;
		}

		while(right != left){
			int curr_citi = queue[left];
			for(int i = 1; i <= graph[curr_citi][0]; i++){
				if(distance[k][graph[curr_citi][i]] == -1){
					distance[k][graph[curr_citi][i]] = distance[k][curr_citi] + 1;
					queue[right++] = graph[curr_citi][i];
				}
			}
			left++;
		}
	}
}


int
main()
{
	int a, b;
	long min;
	scanf("%d %d %d %d %d", &p, &q, &r, &n, &m); // n cities, m lines
	graph = (int**)malloc(sizeof(int*) * (n + 1));
	queue = (int*)malloc(sizeof(int) * (n + 1));
	distance = (int**)malloc(sizeof(int*) * 3);
	for(int i = 0; i < 3; i++){
		distance[i] = (int*)malloc(sizeof(int) * (n + 1));
		memset(distance[i], -1, sizeof(int) * (n + 1));
	}

	for(int i = 0; i < n + 1; i++){
		graph[i] = (int*)malloc(sizeof(int) * (n + 1));
		graph[i][0] = 0;
	}

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		graph[a][++graph[a][0]] = b;
		graph[b][++graph[b][0]] = a;
	}


	doBFS();
	/*
	for(int j = 0; j < 3; j++){
		printf("dist: ");
		for(int i =0; i < n + 1; i++){
			printf("%d ", distance[j][i]);
		}
		puts("");
	}
	*/
	
	long sub_min;
	min = distance[0][1] * r + distance[1][1] * p + distance[2][1] * q;
	for(int i = 2; i <= n; i++){
		sub_min = distance[0][i] * r + distance[1][i] * p + distance[2][i] * q;
		if(min > sub_min) min = sub_min;
	}
	printf("%ld\n", min);
}
