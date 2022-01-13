#include <iostream>

using namespace std;

int combi[41] = {0}, vip[41] = {0};
int n, m, from = 0, ans = 1;

int
main()
{
	combi[0] = 1; combi[1] = 1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &vip[i]);
	vip[m++] = n + 1;

	for(int i = 2; i <= n; i++)
		combi[i] = combi[i-1] + combi[i-2];

	for(int i = 0; i < m; i++){
		ans *= combi[vip[i] - from - 1];
		from = vip[i];
	}
	printf("%d\n", ans);
}
