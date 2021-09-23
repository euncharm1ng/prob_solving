#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned long long ll;

int a, m;
ll *bags, carrier = 0, lowerbound = 0;

int
main()
{
	scanf("%d", &m);
	bags = (ll*)malloc(sizeof(ll) * m + 1);
	memset(bags, 0, sizeof(ll) * m + 1);

	while(scanf("%d", &a) == 1 && !feof(stdin))
		bags[a]++;
/*
	printf("m is %d\n", m);
	for(int i = 0; i < m + 1; i++)
		printf("%lld\n", bags[i]);
*/
	carrier += bags[m];
	bags[m] = 0;
	while(lowerbound < m && bags[lowerbound] == 0) 
		lowerbound++;

	//printf("lowerbound start with %lld\n", lowerbound);

	for(ll i = m - 1; i > lowerbound; i--){
		if(bags[i] == 0) continue;
		if(lowerbound + i <= m){
			if(bags[lowerbound] > bags[i]){
				bags[lowerbound] -= bags[i];
				carrier += bags[i];
				bags[i] = 0;
			}
			else{
				carrier += bags[lowerbound];
				bags[i] -= bags[lowerbound];
				bags[lowerbound] = 0;
				while(lowerbound < i && bags[lowerbound] == 0) lowerbound++;
				i++;
			}
		}
		else{
			carrier += bags[i];
			bags[i] = 0;
		}
	}
//	printf("lowerbound == %lld, bags[lowerbound] == %lld\n", lowerbound, bags[lowerbound]);
	if(bags[lowerbound] > 0){
		if(lowerbound * 2 <= m){
			carrier += bags[lowerbound] / 2 + bags[lowerbound] % 2;
		}
		else
			carrier += bags[lowerbound];
	}
	printf("%lld\n", carrier);
}
