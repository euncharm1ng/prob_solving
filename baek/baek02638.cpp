#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n, m, ans = 0;
int i_start = 101, i_end = -1, j_start = 101, j_end = -1;
char cheese[100][100];
queue<pair<int, int> > air;

int
melt()
{
	int melt_chk, ret = 0;
	for(int i = i_start; i < i_end; i++){
		for(int j = j_start; j < j_end; j++){
			melt_chk = 0;
			if(cheese[i][j] == 1){
				if(i+1 < n && cheese[i+1][j] == 2)
					melt_chk++;
				if(i-1 > -1 && cheese[i-1][j] == 2)
					melt_chk++;
				if(j+1 < m && cheese[i][j+1] == 2)
					melt_chk++;
				if(j-1 > -1 && cheese[i][j-1] == 2)
					melt_chk++;
				if(melt_chk >= 2){
					cheese[i][j] = 0;
					air.push({i, j});
					ret = 1;
				}
			}
		}
	}
	return ret;
}

void 
bfs_fill_air()
{
	pair<int, int> first;
	int i, j;
	while(!air.empty()){
		first = air.front();
		air.pop();
		i = first.first; j = first.second;

		if(i < i_start) i_start = i;
		else if(i+1 > i_end) i_end = i+1;
		if(j < j_start) j_start = j;
		else if(j+1 > j_end) j_end = j+1;

		cheese[i][j] = 2;
		if(i+1 < n && cheese[i+1][j] == 0)
			cheese[i+1][j] = 2, air.push({i+1, j});
		if(i-1 > -1 && cheese[i-1][j] == 0)
			cheese[i-1][j] = 2, air.push({i-1, j});
		if(j+1 < m && cheese[i][j+1] == 0)
			cheese[i][j+1] = 2, air.push({i, j+1});
		if(j-1 > -1 && cheese[i][j-1] == 0)
			cheese[i][j-1] = 2, air.push({i, j-1});
	}
}

int
main()
{
	memset(cheese, 0, sizeof(char) * 100 * 100);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%hhd", &cheese[i][j]);
			if(cheese[i][j] == 1){
				if(i < i_start) i_start = i;
				else if(i+1 > i_end) i_end = i+1;
				if(j < j_start) j_start = j;
				else if(j+1 > j_end) j_end = j+1;
			}
		}
	}
	if(i_end == -1) i_end = i_start + 1;
	if(j_end == -1) j_end = j_start + 1;

	air.push({0, 0});
	bfs_fill_air();
	while(melt()){
		bfs_fill_air();
		ans++;
	}
	printf("%d\n", ans);
}
