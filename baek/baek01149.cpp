#include <iostream>
#include <algorithm>

using namespace std;

int n;
int color[1000][3];

void
select_prev_min(int level)
{
	int prev = level-1;
	color[level][0] += min(color[prev][1], color[prev][2]);
	color[level][1] += min(color[prev][0], color[prev][2]);
	color[level][2] += min(color[prev][0], color[prev][1]);
}

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);

	for(int i = 1; i < n; i++){
		select_prev_min(i);
	}
	printf("%d\n", min(color[n-1][0], min(color[n-1][1], color[n-1][2])));
}
