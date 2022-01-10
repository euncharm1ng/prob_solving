#include <iostream>

using namespace std;

long long ans[1000001] = {0}, n, _a, cal_to = 3;

int
main()
{
	ans[1] = 1; ans[2] = 2, ans[3] = 4;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &_a);
		while(_a >= cal_to){
			cal_to++;
			ans[cal_to] = (ans[cal_to-1] + ans[cal_to-2] + ans[cal_to-3]) % 1000000009;
		}
		printf("%lld\n", ans[_a]);
	}
}
