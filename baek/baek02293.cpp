#include <iostream>

using namespace std;

int coin[100], ans[10001] = {0};
int n, k;

int
main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	ans[0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = coin[i]; j <= k; j++){
			ans[j] += ans[j - coin[i]];
		}
	}
	printf("%d\n", ans[k]);
}
