#include <iostream>
#include <algorithm>

using namespace std;

int n, d, m, task[100000], k;
int min_k, max_k;

inline int
ceiling(int a, int b)
{ return (a + b -1) / b; }

int
bin_search(int bull)
{
	/*
	//printf("\n%d bulls:\n", bull);
	for(int i = 0; i < n; i++){
		//printf("\tday %d: ", i);
		for(int j = 0; j < bull && i*bull+j < m; j++){
			//printf("%d+%d ", task[i*bull+j], i*bull+j);
			if(task[i*bull+j]+d <= i+1) return -1;
		}
		//puts("");
	}
	return 1;
	*/

	int day = 1, task_cnt = 0;
	for(int i = 0; i < m; i++){
		if(task[i]+d < day+1) return -1;
		task_cnt++;
		if(task_cnt == bull){task_cnt = 0; day++;}
	}
	return 1;
}

int 
main()
{
	int mid;
	scanf("%d %d %d", &n, &d, &m);

	min_k = ceiling(m, n) - 1;
	max_k = ceiling(m, d) + 1; // +1 or not?

	for(int i = 0; i < m; i++)
		scanf("%d", &task[i]);
	
	sort(task, task+m);

	//for(int i = 0; i < m; i++) printf("%d ", task[i]);

	while(min_k + 1 < max_k){
		mid = (max_k + min_k) / 2;
		printf("\nmin: %d, mid: %d, max: %d\n", min_k, mid, max_k);
		if(bin_search(mid) == 1){
			max_k = mid;
			puts("return 1");
		}
		else{
			min_k = mid;
			puts("return -1");
		}
	}
	//printf("%d\n", max_k);
	printf("ans--> %d\n", max_k);
}
