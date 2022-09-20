#include <stdio.h>

int mat[999][999];
int n, target, target_i, target_j;

void
lap(int num, int width, int pos)
{
	if(num == 1){
		mat[pos][pos] = 1;
		return;
	}
	int curr_num = num * num, i = pos, j = pos;
	for(; i < width-1; i++) mat[i][j] = curr_num--;
	for(; j < width-1; j++) mat[i][j] = curr_num--;
	for(; i > pos; i--) mat[i][j] = curr_num--;
	for(; j > pos; j--) mat[i][j] = curr_num--;
	lap(num-2, width-1, pos+1);
}

int
main()
{
	scanf("%d %d", &n, &target);
	
	lap(n, n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", mat[i][j]);
			if(mat[i][j] == target){
				target_i = i+1; target_j = j+1;
			}
		}
		puts("");
	}
	printf("%d %d\n", target_i, target_j);
}
