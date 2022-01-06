#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int n, m;
int map[1000][1000], dist[1000][1000], broken_dist[1000][1000];
char _a;
queue<pii> broken, no_broken;

inline void
find_broken_path(int i, int j, int curr_dist)
{
	if(map[i][j] == 0) {
		if(broken_dist[i][j] == -1 || broken_dist[i][j] > curr_dist) {
			broken_dist[i][j] = curr_dist;
			broken.push({i, j});
		}
	}
}

void 
find_broken_path()
{
	pii curr;
	int x, y, curr_dist;
	while(!broken.empty()){
		curr = broken.front(); broken.pop();
		x = curr.first; y = curr.second;
		if(x == 0 && y == 0) continue;
		curr_dist = broken_dist[x][y]+1;
		if(x-1 >= 0) find_broken_path(x-1, y, curr_dist);
		if(x+1 < n) find_broken_path(x+1, y, curr_dist);
		if(y-1 >= 0) find_broken_path(x, y-1, curr_dist);
		if(y+1 < m) find_broken_path(x, y+1, curr_dist);
	}
}

inline void
find_dir(int i, int j, int curr_dist)
{
	if(map[i][j] == 0) {
		if(dist[i][j] == -1 || dist[i][j] > curr_dist) {
			dist[i][j] = curr_dist;
			no_broken.push({i, j});
		}
	}
	else if(broken_dist[i][j] == -1|| curr_dist < broken_dist[i][j]){
		broken_dist[i][j] = curr_dist;
		broken.push({i, j});
	}
}

void
find_path()
{
	pii curr;
	int x, y, curr_dist;
	while(!no_broken.empty()){
		curr = no_broken.front(); no_broken.pop();
		x = curr.first; y = curr.second;

		if(x == 0 && y == 0) continue;
		curr_dist = dist[x][y]+1;

		if(x-1 >= 0) find_dir(x-1, y, curr_dist);
		if(x+1 < n) find_dir(x+1, y, curr_dist);
		if(y-1 >= 0) find_dir(x, y-1, curr_dist);
		if(y+1 < m) find_dir(x, y+1, curr_dist);
	}
}

int
main()
{
	memset(map, 0 ,sizeof(int) * 1000 * 1000);
	memset(dist, -1 ,sizeof(int) * 1000 * 1000);
	memset(broken_dist, -1 ,sizeof(int) * 1000 * 1000);
	scanf("%d %d ", &n, &m); 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%c", &_a);
			if(_a == '0') map[i][j] = 0;
			else if(_a == '1') map[i][j] = 1;
			else map[i][j] = 2;
		}
		getchar();
	}
	dist[n-1][m-1] = 1;
	no_broken.push({n-1, m-1});

	find_path();
	find_broken_path();

	if(dist[0][0] == -1) printf("%d\n", broken_dist[0][0]);
	else if (broken_dist[0][0] == -1) printf("%d\n", dist[0][0]);
	else printf("%d\n", min(dist[0][0], broken_dist[0][0]));
}
