#include <iostream>

using namespace std;

char curr;
int n, m, ans = 64;
int board[50][50], colored_board[50][50];

void 
print_color()
{
	int row_start = 0, curr_color = 0, change_cnt;
	for(int i = 0; i < n; i++){
		curr_color = row_start;
		for(int j = 0; j < m; j++){
			if(board[i][j] != curr_color) colored_board[i][j] = 1;
			else colored_board[i][j] = 0;
			curr_color ^= 1;
		}
		row_start ^= 1;
	}

	for(int i = 0; i < n-7; i++){
		for(int j = 0; j < m-7; j++){
			change_cnt = 0;
			for(int k = 0; k < 8; k++){
				for(int l = 0; l < 8; l++){
					change_cnt += colored_board[i+k][j+l];
				}
			}
			ans = min(ans, min(change_cnt, 64-change_cnt));
		}
	}
}

int
main()
{
	scanf("%d %d ", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%c", &curr);
			if(curr == 'B') board[i][j] = 0;
			else board[i][j] = 1;
		}
		getchar();
	}
	print_color();
	printf("%d\n", ans);
}
