#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, h, w, block_cnt = 0, square_width, max_width = 0, temp;
int ***poly, polyhw[5][3], **ans;
float root;

float
my_sqrt(float num)
{
	float root = num / 2, temp;
	do{
		temp = root;
		root = (temp + num / temp) / 2;
	}while(temp != root);
	return root;
}

int
max(int a, int b)
{
	if(a > b) return a;
	else return b;
}

void
sort_poly()
{
	for(int i = 0; i < n; i++){
		int swap = i, max_side = max(polyhw[i][0], polyhw[i][1]);
		for(int j = i + 1; j < n; j++){
			int curr = max(polyhw[j][0], polyhw[j][1]);
			if(max_side < curr){
				max_side = curr;
				swap = j;
			}
		}
		int** temp = poly[swap];
		poly[swap] = poly[i];
		poly[i] = temp;
		int temph = polyhw[swap][0], tempw = polyhw[swap][1], tempn = polyhw[swap][2];
		polyhw[swap][0] = polyhw[i][0];
		polyhw[swap][1] = polyhw[i][1];
		polyhw[swap][2] = polyhw[i][2];
		polyhw[i][0] = temph; polyhw[i][1] = tempw; polyhw[i][2] = tempn;
	}
}

void
rollback(int target)
{
	for(int i = 0; i < square_width; i++){
		for(int j = 0; j < square_width; j++){
			if(ans[i][j] == target) ans[i][j] = 0;
		}
	}
}

int
try_insert(int curr)
{
	if(curr == n) return 0;
	int chkroll = 0;
	for(int i = 0; i <= square_width - polyhw[curr][0]; i++){
		for(int j = 0; j <= square_width - polyhw[curr][1]; j++){

			for(int k = 0; k < polyhw[curr][0]; k++){
				for(int l = 0; l < polyhw[curr][1]; l++){
					if(poly[curr][k][l] == 0) continue;
					else if(ans[i+k][j+l] != 0) {chkroll = 1; break;}
					else ans[i+k][j+l] = poly[curr][k][l];
				}
				if(chkroll == 1) break;
			}

			if(chkroll == 1) chkroll = 0;
			else if(curr == n - 1) return 1;
			else if(try_insert(curr+1) == 1) return 1;

			rollback(polyhw[curr][2]);
		}
	}
	return 0;
}

int
main()
{
	
	poly = (int***)malloc(sizeof(int**) * 5);
	for(int i = 0; i < 5; i++){
		poly[i] = (int**)malloc(sizeof(int*) * 4);
		for(int j = 0; j < 4; j++){
			poly[i][j] = (int*)malloc(sizeof(int) * 4);
			memset(poly[i][j], 0, sizeof(int) * 4);
		}
	}

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &h, &w);
		polyhw[i][0] = h; polyhw[i][1] = w; polyhw[i][2] = i + 1;
		if(max_width < max(h, w)) max_width = max(h, w);	
		for(int j = 0; j < h; j++){
			for(int k = 0; k < w; k++){
				scanf("%d", &temp);
				if(temp == 1){
					poly[i][j][k] = i + 1;
					block_cnt++;
				}
			}
		}
	}
	printf("__%d\n", block_cnt);
	root = my_sqrt(block_cnt);
	if((int)root != root || root < max_width){
		printf("No solution possible\n");
		return 0;
	}
	//sort_poly(poly, polyhw, n);
	//====
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				printf("%d ", poly[i][j][k]);
			}
			puts("");
		}
		puts("--");
	}
	for(int i = 0; i < 5; i++){
		printf("%d %d\n", polyhw[i][0], polyhw[i][1]);
	}
	//====
	square_width = root;
	ans = (int**)malloc(sizeof(int*) * square_width);
	for(int i = 0; i < square_width; i++){
		ans[i] = (int*)malloc(sizeof(int) * square_width);
		memset(ans[i], 0, square_width * sizeof(int));
	}
	printf("try insert: %d === \n", try_insert(0));

	for(int i = 0; i < square_width; i++){
		for(int j = 0; j < square_width; j++){
			printf("%d ", ans[i][j]);
		}
		puts("");
	}
}
