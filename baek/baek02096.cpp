#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int tower[100000][3];

void
max()
{
	int ans[3] = {0};
	for(int i = 0; i < n; i++){
		int one = max(ans[0], ans[1]), two = max(ans[1], ans[2]);
		ans[0] = one + tower[i][0];
		ans[1] = max(one, two) + tower[i][1];
		ans[2] = two + tower[i][2];
	}
	printf("%d ", max(max(ans[0], ans[1]), ans[2]));
}
void
min()
{
	int ans[3] = {0};
	for(int i = 0; i < n; i++){
		int one = min(ans[0], ans[1]), two = min(ans[1], ans[2]);
		ans[0] = one + tower[i][0];
		ans[1] = min(one, two) + tower[i][1];
		ans[2] = two + tower[i][2];
	}
	printf("%d ", min(min(ans[0], ans[1]), ans[2]));
}

int
main()
{
	memset(tower, 0, sizeof(char) * 3 * 100000);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &tower[i][0], &tower[i][1], &tower[i][2]);
	}
	max();
	min();
}
