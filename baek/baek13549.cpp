#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int n, k, map[100001] = {0};
deque<int> bfs;

int
find()
{
	int curr, curr_move;
	while(!bfs.empty()){
		curr = bfs.front(); bfs.pop_front();
		curr_move = map[curr];
		if(curr == k) return curr_move;
		if (curr*2 <= 100000 && map[curr*2] == -1){
				map[curr*2] = curr_move;
				bfs.push_front(curr*2);
		}
		if(curr-1 >= 0 && map[curr-1] == -1){
				map[curr-1] = curr_move + 1;
				bfs.push_back(curr-1);
		}
		if (curr+1 <= 100000 && map[curr+1] == -1){
				map[curr+1] = curr_move + 1;
				bfs.push_back(curr+1);
		}
	}
}

int
main()
{
	memset(map, -1, sizeof(int) * 100001);
	scanf("%d %d", &n, &k);
	if(n == k){ printf("0\n"); return 0; }
	bfs.push_back(n);
	map[n] = 0;
	printf("%d\n", find());
}
