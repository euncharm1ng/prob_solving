#include <iostream>

using namespace std;
#define MOD 1000000007
#define POW 1000000005
typedef long long ll;

int m;
ll _a, _b, ans = 0;


ll
power(ll base, ll exponent)
{
	ll ret = 1;
	while(exponent){
		if(exponent & 1) ret = (ret * base) % MOD;
		exponent /= 2;
		base = (base * base) % MOD;
	}
	return ret % MOD;
}

int
main()
{
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%lld %lld", &_b, &_a);
		ans = (ans + (_a * power(_b, POW))) % MOD;
	}
	printf("%lld\n", ans % MOD);
}
