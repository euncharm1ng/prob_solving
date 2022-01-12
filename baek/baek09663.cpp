#include <iostream>
#include <cstring>

using namespace std;
char board[14][14];
int n, ans = 0;

void
place_queen(int row)
{
	int left, right, up, j;
	if(row == 0){
		for(int i = 0; i < n; i++)
			if(board[0][i] == 0) ans++;
		return;
	}
	for(int i = 0; i < n; i++){
		if(board[row][i] == 0){
			board[row][i]++;
			left = i - 1; right = i + 1; up = i;
			for(j = row-1; j >= 0; j--, left--, right++){
				if(left >= 0) board[j][left]++;
				if(right < n) board[j][right]++;
				board[j][up]++;
			}
			place_queen(row-1);
			for(j++, left++, right--; j < row; j++, left++, right--){
				if(left >= 0) board[j][left]--;
				if(right < n) board[j][right]--;
				board[j][up]--;
			}
			board[row][i]--;
		}
	}
}

int 
main()
{
	memset(board, 0, sizeof(char) * 14 * 14);
	scanf("%d", &n);
	place_queen(n-1);
	printf("%d\n", ans);
}
