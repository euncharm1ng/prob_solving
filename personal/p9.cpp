#include <iostream>
#include <string.h>

using namespace std;

int tumor[451][451];

int
chk_relation(int i, int j)
{
	int queue[450] = {0}, q_size = 0, ret = 0;
	for(int prev_row = i-1; prev_row > 0; prev_row--){
		if(tumor[prev_row][i] != 0 && tumor[prev_row][j] != 0){
			if(tumor[prev_row][prev_row] > ret) ret = tumor[prev_row][prev_row];
			queue[q_size++] = prev_row;
		}
	}

	for(int k = q_size-1; k >= 0; k--){
		for(int l = k-1; l >= 0; l--){
			if(tumor[queue[k]][queue[l]] > ret) ret = tumor[queue[k]][queue[l]];
		}
	}

	return ret;
}

int
main()
{
	int n, b, ans = 0, _a, _b;
	memset(&(tumor[0][0]), 0, sizeof(int)*451*451);

	scanf("%d %d", &n, &b);
	for(int i = 1; i <= n; i++) scanf("%d", &tumor[i][i]);

	for(int i = 0; i < b; i++){
		scanf("%d %d", &_a, &_b);
		if(_a < _b) tumor[_a][_b] = 1;
		else tumor[_b][_a] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			if(tumor[i][j] != 0){
				tumor[i][j] = chk_relation(i, j) + tumor[i][i] + tumor[j][j];
				if(tumor[i][j] > ans) ans = tumor[i][j];
			}
		}
	}

	printf("%d\n", ans);
}
