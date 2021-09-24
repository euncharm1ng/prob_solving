#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ll;

int a, m;
ll *bags, carrier = 0, lower = 0;

int
main()
{
	scanf("%d", &m);
	if(m == 0){
		printf("0\n");
		return 0;
	}

	bags = (ll*)malloc(sizeof(ll) * m + 1);
	memset(bags, 0, sizeof(ll) * m + 1);

	while(scanf("%d", &a) == 1 && !feof(stdin))
		bags[a]++;

	carrier += bags[m];
	bags[m] = 0;

	while(lower < m && bags[lower] == 0) 
		lower++;
		
	for(ll upper = m - 1; upper > lower; upper--){
		if(bags[upper] == 0) 
			continue;
		if(lower + upper <= m){
			if(bags[lower] > bags[upper]){
				bags[lower] -= bags[upper];
				carrier += bags[upper];
				bags[upper] = 0;
			}
			else{
				carrier += bags[lower];
				bags[upper] -= bags[lower];
				bags[lower] = 0;
				while(lower < upper && bags[lower] == 0) 
					lower++;
				upper++;
			}
		}
		else{
			carrier += bags[upper];
			bags[upper] = 0;
		}
	}


	if(bags[lower] > 0){
		if(lower * 2 <= m)
			carrier += bags[lower] / 2 + bags[lower] % 2;
		else
			carrier += bags[lower];
	}

	printf("%lld\n", carrier);
}
