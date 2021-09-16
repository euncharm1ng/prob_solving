#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **mount, **score, n, max = 0;

int
return_max(int a, int b, int c, int d){
	int to_return = a > b ? a : b;
	to_return = to_return > c ? to_return : c;
	return to_return > d ? to_return : d;	
}


int
search(int i, int j, char dir_from)//left, right, top, bot, nowhere
{
	// if(height_of_from <= mount[i][j]) return 0;
	if(score[i][j] != -1) return score[i][j]; 
	
	int r_score, l_score, t_score, b_score, curr_height = mount[i][j];
	r_score = l_score = t_score = b_score = - curr_height;

	if(dir_from != 'l' && j != 0 && curr_height > mount[i][j-1]) 
		r_score = search(i, j - 1, 'r') - mount[i][j-1];
	if(dir_from != 'r' && j != n - 1 && curr_height > mount[i][j+1]) 
		l_score = search(i, j + 1, 'l') - mount[i][j+1];
	if(dir_from != 't' && i != 0 && curr_height > mount[i-1][j]) 
		b_score = search(i - 1, j, 'b') - mount[i-1][j];
	if(dir_from != 'b' && i != n - 1 && curr_height > mount[i+1][j]) 
		t_score = search(i + 1, j, 't') - mount[i+1][j];

 	score[i][j] = return_max(r_score, l_score, t_score, b_score) + curr_height;
	if(score[i][j] > max) max = score[i][j];
	return score[i][j];
}

int 
main()
{
	scanf("%d", &n);
	mount = (int**)malloc(sizeof(int*) * n);
	score = (int**)malloc(sizeof(int*) * n);

	for(int i = 0; i < n; i++){
		mount[i] = (int*)malloc(sizeof(int) * n);
		score[i] = (int*)malloc(sizeof(int) * n);
		memset(score[i], -1, sizeof(int)*n);
		for(int j =0; j < n; j++){
			scanf("%d", &mount[i][j]);	
		}
	}	
/*
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			printf("%2d ", mount[i][j]); 
		}
		puts("");
	}
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			printf("%2d ", score[i][j]); 
		}
		puts("");
	}
*/
	for(int i =0; i < n; i++){
		for(int j =0; j < n; j++){
			if(score[i][j] == -1) search(i, j, 'n');
		}
	}
/*
	puts("here");
	for(int i = 0; i < n; i++){
		for(int j =0; j < n; j++){
			printf("%2d ", score[i][j]); 
		}
		puts("");
	}
*/
	printf("%d\n", max);
}
