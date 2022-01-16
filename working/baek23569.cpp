#include <iostream>

using namespace std;

int n, m, _a, _b;
int friendship[1001][1001];

int 
main()
{
	memset(friendship, 0, sizeof(int)*1001*1001);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &_a, &_b);
		/*
		friendship[_a][++friendship[_a][0]] = _b;
		friendship[_b][++friendship[_b][0]] = _a;
		*/
		friendship[_a][_b] = 1;
		friendship[_b][_a] = 1;
	}
	/*
	for(int i = 1; i <= n; i++){
		printf("%d ++ %d -> ", i, friendship[i][0]);
		for(int j = 1; j <= friendship[i][0]; j++)
			printf("%d ", friendship[i][j]);
		puts("");
	}
	*/
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", friendship[i][j]);
		puts("");
	}
}
