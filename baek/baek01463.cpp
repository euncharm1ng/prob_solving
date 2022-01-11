#include <iostream>

using namespace std;
#define INF 1e9

int n, div2, div3, sub1;
int ans[1000001] = {0};

int
main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		div2 = div3 = INF;
		if(!(i%2)) div2 = ans[i/2]+1;
		if(!(i%3)) div3 = ans[i/3]+1;
		ans[i] = min(ans[i-1]+1, min(div2, div3));
	}
	printf("%d\n", ans[n]);
}
