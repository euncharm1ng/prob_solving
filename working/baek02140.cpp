#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int mat[100][100], row[4][100]
int n, k;
char c;

int 
main()
{
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++) mat[i][j] = 0;
	}
	scanf("%d ", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%c ", &c);
			if(isdigit(c)) {
				mat[i][j] = atoi(&c);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) 
			printf("%d ", mat[i][j]);
		puts("");
	}
	for(int i = 0; i < 2; i++){
		if(mat[i*n][0] == 1) row[0][0] = 1
		for(int j = 1; j < n; j++){
			if(mat[i*n][j-1]
		}
	}
}
