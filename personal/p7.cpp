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
	int loop = ceiling(m, bull);
	printf("loop -> %d\n", loop);
	for(int i = 0; i < loop; i++){
		for(int j = i*bull; j < i*bull + bull; j++){
			if(task[j] > i + d + 1) return -1;
		}
	}
	return 1;
}

int 
main()
{
	scanf("%d %d %d", &n, &d, &m);

	min_k = ceiling(m, n);
	max_k = ceiling(m, d+1); // +1 or not?

	for(int i = 0; i < m; i++)
		scanf("%d", &task[i]);
	
	sort(task, task+m);

	for(int i = 0; i < m; i++)
		printf("%d ", task[i]);
	puts("");
	printf("start with %d, max %d\n", min_k, max_k);
	printf("with 1, result %d\n", bin_search(1));
	printf("with 2, result %d\n", bin_search(2));
	printf("with 3, result %d\n", bin_search(3));
	printf("with 4, result %d\n", bin_search(4));
}
