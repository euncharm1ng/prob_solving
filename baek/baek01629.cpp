#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull a, b, c;

ull
modulo(ull pow)
{
	if(pow == 1) return a;
	ull ret = modulo(pow/2) % c;
	ret = (ret * ret) % c;
	if (pow % 2) return (ret * a) % c;
	else return ret;
}
int 
main()
{
	scanf("%lld %lld %lld", &a, &b, &c);
	a %= c;
	printf("%lld", modulo(b));
	return 0;
}
