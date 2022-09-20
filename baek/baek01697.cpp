#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

int pos[100001];
int n, m;
queue<int> que;

void
chase()
{
	int curr_pos, curr_time;
	while(pos[m] == -1){
		curr_pos = que.front(); que.pop();
		curr_time = pos[curr_pos];
		if(curr_pos+1 <= m && pos[curr_pos+1] == -1){
			pos[curr_pos+1] = curr_time + 1;
			que.push(curr_pos+1);
		}
		if(curr_pos-1 >= 0 && pos[curr_pos-1] == -1){
			pos[curr_pos-1] = curr_time +1;
			que.push(curr_pos-1);
		}
		if(curr_pos*2 <= 100000 && pos[curr_pos * 2] == -1){
			pos[curr_pos*2] = curr_time + 1;
			que.push(curr_pos*2);
		}
	}
}

int
main()
{
	memset(pos, -1, 100001 * sizeof(int));
	scanf("%d %d", &n, &m);
	if(m < n){
		printf("%d\n", n-m);
		return 0;
	}
	pos[n] = 0;
	que.push(n);
	chase();
	printf("%d\n", pos[m]);
}
