#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n, m, witness_cnt, _a, ans;
int witness[51] = {0};
int relation[51][51];
int group[50][51];
queue<int> witness_q;

void 
set_relation()
{
	for(int k = 0; k < m; k++){
		for(int i = 1; i <= group[k][0]-1; i++){
			for(int j = i+1; j <= group[k][0]; j++){
				relation[group[k][j]][group[k][i]] = 1;
				relation[group[k][i]][group[k][j]] = 1;
			}
		}
	}
}

void print_relation()
{
	for(int i = 1; i <= n; i++){
		printf("%d ", i);
		for(int j = 1; j <= n; j++){
			printf("%d ", relation[i][j]);
		}
		puts("");
	}
}

void 
set_witness()
{
	int ind;
	while(witness_q.size() != 0){
		ind = witness_q.front();
		if(witness[ind]) ;
		else{
			witness[ind] = 1;
			for(int i = 1; i <= n; i++){
				if(relation[ind][i] && !witness[i]) witness_q.push(i);
			}
		}
		witness_q.pop();
	}
}

int 
main()
{
	memset(relation, 0, sizeof(int) * 51 * 51);
	scanf("%d %d", &n, &m);
	scanf("%d", &witness_cnt);
	if(witness_cnt == 0) {printf("%d\n", m); return 0;}
	for(int i = 0; i < witness_cnt; i++){
		scanf("%d", &_a);
		witness_q.push(_a);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &group[i][0]);
		for(int j = 1; j <= group[i][0]; j++)
			scanf("%d", &group[i][j]);
	}
	set_relation();
	set_witness();
	ans = m;

	for(int i = 0; i < m; i++){
		if(witness[group[i][1]]) ans--;
	}
	printf("%d\n", ans);

	return 0;
}
