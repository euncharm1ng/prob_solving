#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef long long ll;

int a, m;
ll *bags, carrier = 0, lowerbound = 0;

int
main()
{
	scanf("%d", &m);
	bags = (ll*)malloc(sizeof(ll) * m + 1);
	memset(bags, 0, sizeof(ll) * m + 1);

//	printf("m is %d\n", m);
	while(scanf("%d", &a) == 1 && !feof(stdin)){
		bags[a]++;
	}
/*
	for(int i = 0; i < m + 1; i++){
		printf("%lld\n", bags[i]);
	}
*/
	carrier += bags[m];

	while(bags[lowerbound] == 0) lowerbound++;
	if(lowerbound > m) lowerbound = m;
	bags[m] = 0;

//	printf("lowerbound start with %d\n", lowerbound);

	for(ll i = m - 1; i > lowerbound; i--){
		if(bags[i] == 0) continue;
		if(lowerbound + i <= m){
			if(bags[lowerbound] > bags[i]){
				bags[lowerbound] -= bags[i];
				carrier += bags[i];
				bags[i] = 0;
			}
			else{
				carrier += bags[i];
				bags[i] = 0;
				bags[lowerbound] = 0;
				while(bags[lowerbound] == 0) lowerbound++;
			}
		}
		else{
			carrier += bags[i];
			bags[i] = 0;
		}
	}
//	printf("lowerbound == %d, bags[lowerbound] == %lld\n", lowerbound, bags[lowerbound]);
	if(bags[lowerbound] > 0){
		if(lowerbound * 2 <= m){
			carrier += bags[lowerbound] / 2 + bags[lowerbound] % 2;
		}
		else
			carrier += bags[lowerbound];
	}
	printf("%lld\n", carrier);
}
