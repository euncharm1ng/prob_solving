#include <iostream>
#include <vector>

using namespace std;

int n, _a, ans_size = 1;
vector<int> seq[1000000];
int ans[1000000] = {0};

void
bin_search(int target)
{
	int left = -1, right = ans_size, mid;
	if(target > seq[ans_size-1].back()){
		seq[ans_size] = seq[ans_size-1];
		seq[ans_size].push_back(target);
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
	seq[right] = seq[right-1];
	seq[right].push_back(target);
}

int
main()
{
	scanf("%d", &n);
	scanf("%d", &_a); ans[0] = _a; 
	seq[0].push_back(_a);
	for(int i = 1; i < n; i++){
		scanf("%d", &_a);
		bin_search(_a);
	}
	printf("%d\n", ans_size);
	for(int i = 0; i < seq[ans_size-1].size(); i++)
		printf("%d ", seq[ans_size-1][i]);
	puts("");
}
