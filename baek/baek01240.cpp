#include <stdio.h>
#define INF 2e8;

int map[1001][1001];
int node_cnt, ins_cnt, a, b, dist; 

void
floyd_warshall()
{
	for(int i = 1; i <= node_cnt; i++){
		for(int j = 1; j <= node_cnt; j++){
			if(i == j) continue;
			for(int k = 1; k <=node_cnt; k++){
				if(map[i][j] + map[k][i] < map[k][j])
					map[k][j] = map[i][j] + map[k][i];
			}
		}
	}
}

int 
main()
{
	for(int i = 0; i < 1001; i++){
		for(int j = 0; j < 1001; j++) map[i][j] = INF;
	}


	scanf("%d %d", &node_cnt, &ins_cnt);
	for(int i = 1; i < node_cnt; i++){
		scanf("%d %d %d", &a, &b, &dist);
		map[a][b] = map[b][a] = dist;
	}

	floyd_warshall();

	for(int i = 0; i < ins_cnt; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", map[a][b]);
	}
}
