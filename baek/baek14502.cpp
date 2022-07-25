#include <iostream>
#include <queue>

using namespace std;

int n, m, ans = 0;
int map[8][8], visit[8][8];
queue<pair<int, int>> virus;
int dir_i[4] = {0, 0, 1, -1};
int dir_j[4] = {1, -1, 0, 0}; 
int cnt_1 = 0, cnt_2 = 0;


inline void
backtrack(int i_start, int j_start, int wall_cnt)
{
	if(wall_cnt == 3) {
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				visit[i][j] = map[i][j];
				if(visit[i][j] == 2) virus.push({i, j});
			}
		}
		
		int virus_cnt = 0;
		while(!virus.empty()){
			pair<int, int> coor = virus.front(); virus.pop();
			for(int i = 0; i < 4; i++){
				int next_i = coor.first + dir_i[i];
				int next_j = coor.second + dir_j[i];
				if(next_i == n || next_i < 0 || next_j == m || next_j < 0) continue;
				else if(visit[next_i][next_j] == 0){
					visit[next_i][next_j] = 2;
					virus.push({next_i, next_j});
					virus_cnt++;
				}
			}
		}
		ans = max(ans, n * m - cnt_1 - cnt_2 - virus_cnt - 3);
		return;
	}

	for(int i = i_start; i < n; i++){
		for(int j = j_start; j < m; j++){
			if(map[i][j] == 0){
				map[i][j] = 1;
				backtrack(i, j, wall_cnt+1);
				map[i][j] = 0;
			}
		}
		j_start = 0;
	}
}

int 
main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1) cnt_1++;
			else if(map[i][j] == 2) cnt_2++;
		}
	}
	backtrack(0, 0, 0);
	printf("%d\n", ans);
}
