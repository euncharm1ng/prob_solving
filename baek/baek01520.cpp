#include <iostream>
#include <cstring>

using namespace std;

int n, m, mnt[500][500];
int path_cnt[500][500];

int
dfs(int i, int j)
{
	if(path_cnt[i][j] != -1) return path_cnt[i][j];

	int curr_h = mnt[i][j], ans = 0;
	if(i-1 >= 0 && mnt[i-1][j] < curr_h){
		if(path_cnt[i-1][j] == -1) ans += dfs(i-1, j);
		else ans += path_cnt[i-1][j];
	}
	if(i+1 < n && mnt[i+1][j] < curr_h){
		if(path_cnt[i+1][j] == -1) ans += dfs(i+1, j);
		else ans += path_cnt[i+1][j];
	}
	if(j-1 >= 0 && mnt[i][j-1] < curr_h){
		if(path_cnt[i][j-1] == -1) ans += dfs(i, j-1);
		else ans += path_cnt[i][j-1];
	}
	if(j+1 < m && mnt[i][j+1] < curr_h){
		if(path_cnt[i][j+1] == -1) ans += dfs(i, j+1);
		else ans += path_cnt[i][j+1];
	}
	path_cnt[i][j] = ans;
	return ans;
}

int
main()
{
	memset(path_cnt, -1, sizeof(int) * 500 * 500);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &mnt[i][j]);
		}
	}

	path_cnt[n-1][m-1] = 1;
	printf("%d\n", dfs(0, 0));
}
