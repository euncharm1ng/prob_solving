#include <iostream>
#include <cstring>

using namespace std;

int n, m, s, e, number[2002] = {0};
int mat[2001][2001];

int
calc(int s, int e)
{
	if(mat[s][e] != -1) return mat[s][e];
	else if(number[s] != number[e]){
		mat[s][e] = 0;
		return 0;
	}
	else{
		mat[s][e] = calc(s+1, e-1);
		return mat[s][e];
	}
}

int
main()
{
	memset(mat, -1, sizeof(int) * 2001 * 2001);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &number[i]);
	for(int i = 0; i <= n; i++){
		mat[i][i] = 1;
		if(number[i] == number[i+1]) mat[i][i+1] = 1;
		else mat[i][i+1] = 0;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &s, &e);
		printf("%d\n", calc(s, e));
	}
}
