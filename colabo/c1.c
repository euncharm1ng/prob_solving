#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, k, f; //n: num of soldiers, k: min num of friends, f:total num of friendship relation
int cnt;
int** graph;
void
delete_node(int index)
{
	if(graph[index][0] == -1) return;
	graph[index][0]--;
	if(graph[index][0] < k){
		graph[index][0] = -1;
		cnt--;
		int i = 0;
		while(graph[index][++i] != 0)
			delete_node(graph[index][i]);
	}
}

void
main()
{
	int rela1, rela2;
	scanf("%d %d %d",&n, &k, &f);
	cnt = n;
	graph= (int**)malloc(sizeof(int*) * (n+1));
	for(int i = 0; i < n+1; i++){
		graph[i] = (int*)malloc(sizeof(int) * (f+1));
		memset(graph[i], 0, sizeof(int) * (f+1));
	}

	for(int i = 0; i < f; i ++){
		scanf("%d %d", &rela1, &rela2);
		graph[rela1][++graph[rela1][0]] = rela2;
		graph[rela2][++graph[rela2][0]] = rela1;
	}
	/*
	for(int i = 1; i < n + 1; i++){
		printf("soldier %d : %d = ", i, graph[i][0]);
		for(int j = 1; j < f + 1; j++){
			printf("%2d  ", graph[i][j]);
		}
		puts("");
	}
	*/
	for(int i =1; i < n+1; i++)
		if(graph[i][0] < k) delete_node(i);
	printf("%d\n", cnt);
}
