#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int cities[1001][1001], previ[1001] = {0}, dist[1001], path[1000];
int dept, arrv, _a, _b, _c, n, m, path_cnt = 0;
queue<int> Q;

void
dijstra()
{
	int curr;
	dist[dept] = 0;
	Q.push(dept);
	while(!Q.empty()){
		curr = Q.front(); Q.pop();
		for(int i = 1; i <= 1001; i++){
			if(cities[curr][i] != -1 && 
					(cities[curr][i] + dist[curr] < dist[i] || dist[i] == -1)){
				dist[i] = cities[curr][i] + dist[curr];
				Q.push(i);
				previ[i] = curr;
			}
		}
	}

	curr = arrv;
	while(curr != dept){
		path[path_cnt++] = curr;
		curr = previ[curr];
	}
	path[path_cnt++] = dept;
}

int 
main()
{
	memset(cities, -1, sizeof(int) * 1001 * 1001);
	memset(dist, -1, sizeof(int) * 1001);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		if(cities[_a][_b] > _c || cities[_a][_b] == -1)
			cities[_a][_b] = _c;
	}
	scanf("%d %d", &dept, &arrv);
	dijstra();
	printf("%d\n%d\n", dist[arrv], path_cnt);
	for(int i = path_cnt - 1; i >= 0; i--){
		printf("%d ", path[i]);
	}
}
