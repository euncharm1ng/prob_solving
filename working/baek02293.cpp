#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int coin[100] = {0}, combi[10001] = {0};

int
main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", &coin[i]);
	sort(&coin[0], &coin[n]);
	
	combi[coin[0]] = 1;
	for(int i = coin[0]; i <= k; i++){
		
	}
}
10 - 5 5, 2 2 2 2 2
5 - 5, 2 2 1, 2 1 1 1, 1 1 1 1 1
2 - 2, 1 1

1 - 1, 1
2 - 2, 1 1, 2
3 - 2, 1 1 1, 1 2
4 - 3, 1 1 1 1, 1 1 2, 2 2
5 - 4, 1 1 1 1 1 , 1 1 1 2, 1 2 2, 5
