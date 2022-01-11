#include <iostream>

using namespace std;
#define INF 1e9

int n, div2, div3, sub1;
int ans[1000001] = {0}, from[1000001] = {0};

int
main()
{
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		div2 = div3 = INF;
		if(!(i%2)) div2 = ans[i/2]+1;
		if(!(i%3)) div3 = ans[i/3]+1;
		if(ans[i-1]+1 <= min(div2, div3)){
			ans[i] = ans[i-1]+1;
			from[i] = i-1;
		}
		else if(div2 < min(ans[i-1]+1, div3)){
			ans[i] = div2;
			from[i] = i/2;
		}
		else{
			ans[i] = div3;
			from[i] = i/3;
		}
	}
	printf("%d\n", ans[n]);
	while(n != 0){
		printf("%d ", n);
		n = from[n];
	}
}
