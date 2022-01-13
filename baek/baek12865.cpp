#include <iostream>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

int n, k, curr_w, curr_v, max_val[101][100001];
pii wv[100], curr;

int
main()
{
	memset(max_val, 0, sizeof(int) * 101 * 100001);
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &wv[i].first, &wv[i].second);
	}
	for(int i = 1; i <= n; i++){
		curr = wv[i-1];
		curr_w = curr.first, curr_v = curr.second;
		for(int j = 1; j <= k; j++){
			if(j >= curr_w && max_val[i-1][j] < curr_v + max_val[i-1][j-curr_w])
				max_val[i][j] = curr_v + max_val[i-1][j-curr_w];
			else max_val[i][j] = max_val[i-1][j];
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= k; j++)
			printf("%2d ", max_val[i][j]);
		puts("");
	}
	printf("%d\n", max_val[n][k]);
}
