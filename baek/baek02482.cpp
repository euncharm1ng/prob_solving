#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
#define MOD 1000000003

int n, k, curr = 0, prevv = 1;
ll color[2][1000], ans = 0;

void
toggle()
{ curr = prevv; prevv ^= 1; }

int
main()
{
	memset(color, 0, sizeof(ll) * 2 * 1000);
	scanf("%d %d", &n, &k);

	if(k == 1){ printf("%d\n", n); return 0; }
	else if(n/2 < k){ printf("0\n"); return 0; }

	for(int i = 0; i < n - 2; i++) color[curr][i] = n - i - 2;
	color[curr][0] = color[curr][1];
	toggle();

	for(int i = 3; i <= k; i++){
		for(int j = n - i + 1; j > 0; j--)
			color[curr][j] = (color[curr][j+1] + color[prevv][j+2]) % MOD;
		color[curr][0] = color[curr][1];
		toggle();
	}

	for(int i = 0; color[prevv][i] != 0; i++){
		ans += color[prevv][i];
		ans %= MOD;
	}
	printf("%lld\n", ans % MOD);
}
