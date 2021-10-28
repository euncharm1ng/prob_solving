#include <iostream>

using namespace::std;
int n, card[50000], bigger[50000] = {0}, smaller[50000] = {0};
int
main()
{
	int currbig, currsmall,  ans =0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &card[i]);
	for(int i = n - 1; i > -1; i--){
		currsmall = -1;
		for(int j = i+ 1; j < n; j++){
			if(card[i] > card[j] && smaller[j] > currsmall){
				currsmall = smaller[j];
			}
		}
		smaller[i] = currsmall + 1;
	}
	for(int i = 1; i < n; i++){
		currbig = -1;
		for(int j = 0; j < i; j++){
			if(card[i] > card[j] && bigger[j] > currbig)
				currbig = bigger[j];
		}
		bigger[i] = currbig + 1;
	}
	for(int i = 0; i < n; i++){
		printf("%3d %d %d \n", card[i], bigger[i], smaller[i]);
		if(smaller[i] + bigger[i] + 1 > ans) ans = smaller[i] + bigger[i] + 1;
	}
	printf("%d\n", ans);
}

