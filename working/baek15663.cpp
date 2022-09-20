#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int input[8], visit[8] = {0};

vector<int> stack;

void
dfs()
{
}

int 
main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	sort(&input[0], &input[n]);

	dfs();
}
