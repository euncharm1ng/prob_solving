#include <iostream>

using namespace std;

int n, _a, ans_size = 1;
int ans[1000000] = {0};

void
bin_search(int target)
{
	int left = -1, right = ans_size, mid;
	if(target > ans[ans_size-1]){
		ans[ans_size] = target;
		ans_size++;
		return;
	}
	while(left + 1 < right){
		mid = (left + right) / 2;
		if(ans[mid] < target) left = mid;
		else right = mid;
	}
	ans[right] = target;
}

int
main()
{
	scanf("%d", &n);
	scanf("%d", &_a); ans[0] = _a;
	for(int i = 1; i < n; i++){
		scanf("%d", &_a);
		bin_search(_a);
	}
	printf("%d\n", ans_size);
}
