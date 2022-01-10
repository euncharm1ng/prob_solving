#include <stdio.h>
#include <stdlib.h>

int n, k, *pole;

int
cmp(const void * a, const void * b)
{
	return *(int*)a - *(int*)b;
}

int
check(int dist)
{
	int prev = 0, cnt = 1;
	for(int i = 1; i < n; i++){
		if(pole[i] - pole[prev] >= dist){
			prev = i; cnt++;
		}
	}
	return cnt;
}

int
main()
{
	scanf("%d %d", &n, &k);
	pole = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) scanf("%d", &pole[i]);
	qsort(pole, n, sizeof(int), cmp);

	int right = pole[n-1], left = 1, mid;
	while(left + 1 < right){
		mid = (right + left) / 2;
		if(k > check(mid))
			right = mid;
		else
			left = mid;
	}
	printf("%d", left);
}
