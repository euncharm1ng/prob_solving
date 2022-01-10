#include <iostream>
#include <algorithm>

using namespace std;

int n, d, m, task[100000], k;
int min_k, max_k;

inline int
ceiling(int a, int b)
{ return (a + b -1) / b; }

int
find_next_start(int start, int end, int prev)
{
	while(start+1 < end){
		int mid = (start + end) / 2;
		if(task[mid] == prev) start = mid;
		else end = mid;
	}
	return end;
}

int
bin_search(int bull)
{
	int duedate = 1-d, startdate = 1;
	for(int i = 0; i < m;){
		int end = i+bull-1;
		if(end >= m) end = m-1;
		if(task[i] < duedate) return -1;
		if(task[i] > startdate){
			startdate = task[i];
			duedate = startdate - d;
		}
		else if(task[end] > startdate){
			i = find_next_start(i, end, task[i]);
			startdate = task[i];
			duedate = startdate - d;
		}
		else{
			i += bull; duedate++; startdate++;
		}
	}
	return 1;
}

int 
main()
{
	int mid;
	scanf("%d %d %d", &n, &d, &m);
	for(int i = 0; i < m; i++)
		scanf("%d", &task[i]);
	
	sort(task, task+m);
	min_k = ceiling(m, n+d) - 1;
	max_k = m;

	while(min_k + 1 < max_k){
		mid = (max_k + min_k) / 2;
		if(bin_search(mid) == 1) max_k = mid;
		else min_k = mid;
	}
	printf("%d\n", max_k);
}
