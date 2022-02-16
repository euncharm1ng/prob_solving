#include <iostream>
#define MOD 1000000007
#define TEMP 101

using namespace std;
typedef unsigned long long ull;

ull n, curr = 0, inc = 1, prevv;

int
main()
{
	scanf("%lld", &n);
	for(register int i = 0; i < n; i++){
		if(curr == 0) printf("here, %d\n", i);
		prevv = curr;
		curr += inc;
		inc = prevv;
		curr %= TEMP;
	}
	printf("%lld\n", curr);
}
