#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int triangle[2][500];
int curr_row = 0, prev_row = 1;
int n, _a, max_ind = 1, ans = 0;

void toggle(){ prev_row = curr_row; curr_row ^= 1; }

void
accum(int val, int ind)
{
	if(ind == 0)
		triangle[curr_row][ind] = val + triangle[prev_row][ind];
	else if(ind == max_ind){
		triangle[curr_row][ind] = val + triangle[prev_row][max_ind-1];
		max_ind++;
	}
	else
		triangle[curr_row][ind] = val + max(triangle[prev_row][ind-1], triangle[prev_row][ind]);
}
int 
main()
{
	memset(triangle, 0, sizeof(int) * 500 * 2);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			scanf("%d", &_a);
			accum(_a, j);
		}
		toggle();
	}
	for(int j = 0; j < n; j++){
		if(ans < triangle[prev_row][j]) 
			ans = triangle[prev_row][j];
	}
	printf("%d\n", ans);
	return 0;
}
