/// d'Ocagne's identity: fib(m+n) = fib(m-1) * fib(n) + fib(m) * fib(n+1)
/// expanding d'Ocagne's identity:
///		fib(2n) = (fib(n) * fib(n-1) + fib(n) * fib(n+1))
///				= fib(n) * (2 * fib(n+1) - fib(n))
///		fib(2n+1) = fib(n)^2 + fib(n+1)^2

#include <iostream>
#include <map>

using namespace std;
#define MOD 1000000007
typedef unsigned long long ull;
typedef pair<ull, int> pui;

ull n;
map<ull, int> fibs;

int
fib(ull curr)
{
	ull _n, _m;
	int ret;
	auto _n_container = fibs.find(curr/2), _m_container = fibs.find(curr/2+1);

	if(_n_container == fibs.end()) _n = fib(curr/2);
	else _n = _n_container->second;
	if(_m_container == fibs.end()) _m = fib(curr/2+1);
	else _m = _m_container->second;

	if(curr % 2) ret = (int)(((_n * _n % MOD) + (_m * _m % MOD)) % MOD);
	else ret = (int)((_n * ((2 * _m + MOD - _n) % MOD)) % MOD);
	fibs.insert(pui(curr, ret));
	return ret;
}

int
main()
{
	scanf("%lld", &n);
	fibs.insert(pui(0, 0));
	fibs.insert(pui(1, 1));
	fibs.insert(pui(2, 1));
	printf("%d\n", fib(n));
}
