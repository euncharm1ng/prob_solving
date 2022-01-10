#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main()
{
	int n, k;
	long ans = 0;
	scanf("%d %d", &n, &k);
	int disk[n+1];
	for(int i = 1; i < 4; i++){
		int a, b;
		scanf("%d",&a);
		for(int j = 0; j < a; j++){
			scanf("%d", &b);
			disk[b] = i;
		}
	}

	while(disk[n] == k) n--;
	int from = disk[n], to = k;
	ans += pow(2, n - 1);
	for(int i = n - 1; i > 0; i--){
		if(disk[i] == from){
			ans+= pow(2, i - 1);
			to = 6 - from - to;
		}
		else if(disk[i] == to){
			ans += pow(2, i - 1);
			int temp = to;
			to = 6 - from - to;
			from = temp;
		}
	}
	printf("%ld\n", ans);
}

