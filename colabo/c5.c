#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, square_width, ***poly, polyhw[5][3], **ans;

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
			else if(curr == n - 1 || try_insert(curr+1) == 1) return 1;

			rollback(polyhw[curr][2]);
		}
	}
	return 0;
}

int
main()
{
	int h, w, block_cnt = 0, max_width = 0, temp;
	float root;

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

	root = my_sqrt(block_cnt);
	if((int)root != root || root < max_width);
	else{
		square_width = root;
		ans = (int**)malloc(sizeof(int*) * square_width);
		for(int i = 0; i < square_width; i++){
			ans[i] = (int*)malloc(sizeof(int) * square_width);
			memset(ans[i], 0, square_width * sizeof(int));
		}

		if (try_insert(0) == 1){
			for(int i = 0; i < square_width; i++){
				for(int j = 0; j < square_width; j++)
					printf("%d ", ans[i][j]);
				puts("");
			}
			return 0;
		}
	}
	puts("No solution possible");
	return 0;
}
