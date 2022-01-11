#include <iostream>
#include <cstring>

using namespace std;

int score[2][100000], t, n;
int ans[2][100000];

void
calc()
{
	memset(ans, 0, sizeof(int) * 2 * 100000);
	ans[0][0] = score[0][0];
	ans[1][0] = score[1][0];
	ans[0][1] = score[1][0] + score[0][1];
	ans[1][1] = score[0][0] + score[1][1];
	for(int i = 2; i < n; i++){
		ans[0][i] = score[0][i];
		ans[0][i] += max(ans[1][i-1], ans[1][i-2]);
		ans[1][i] = score[1][i];
		ans[1][i] += max(ans[0][i-1], ans[0][i-2]);
	}
	printf("%d\n", max(ans[0][n-1], ans[1][n-1]));
}

int
main()
{
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < n; k++){
				scanf("%d", &score[j][k]);
			}
		}
		calc();
	}
}
