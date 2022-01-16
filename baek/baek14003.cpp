#include <iostream>

using namespace std;

int n, max_size = 0, find_start;
int num[1000000], lis_cnt[1000000] = {0}, lis_max[1000000] = {0};
int seq[1000000] = {0};

void
bin_search(int target, int target_ind)
{
	int left = -1, right = max_size, mid;
	while(left+1 < right){
		mid = (left + right) / 2;
		if(lis_max[mid] < target) left = mid;
		else right = mid;
	}
	lis_max[right] = target;
	lis_cnt[target_ind] = right;
	if(max_size == right){
		max_size++;
		find_start = target_ind;
	}
}

void
find_sub(){
	int curr_len = max_size - 2, prev = num[find_start];
	seq[max_size-1] = num[find_start];
	for(int i = find_start-1; i >= 0 && curr_len >= 0; i--){
		if(lis_cnt[i] == curr_len && num[i] < prev){
			prev = num[i];
			seq[curr_len--] = num[i];
		}
	}
}

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	for(int i = 0; i < n; i++)
		bin_search(num[i], i);
	find_sub();
	
	printf("%d\n", max_size);
	for(int i = 0; i < max_size; i++)
		printf("%d ", seq[i]);
	puts("");
}
