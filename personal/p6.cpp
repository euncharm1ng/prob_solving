#include <iostream>

using namespace::std;

int n, cable[500];

int
calc(int* front, int* rear)
{
	int *r = rear, *l = front, rsum =*r, lsum = *l, sum = 0;
	int *curr = front;
/*
	printf("\t arr: ");
	while(curr <= rear){ 
		sum+= *curr;
		printf("%d ", *curr); 
		curr++; 
	}
	puts("");
	*/

	if(front+1 == rear) return *front + *rear;
	else if (front == rear) return 0;

	while(1){
		if(rsum > lsum){
			l++;
			lsum += *l;
			sum -= *l;
		}
		else{
			r--;
			rsum += *r;
			sum -= *r;
		}
		if(l+1 == r) break;
		/*
		if(l > r) {
			printf("here:  %d %d\n", *l, *r);
			break;
		}
		if(l > r || (rsum > sum && lsum > sum)) break;
		*/
	}
	printf("here:  %d %d\n", *l, *r);
	printf("lsum: %d, sum: %d, rsum: %d\n", lsum, sum, rsum);
	return rsum + lsum + calc(front, l) + calc(r, rear);
	/*
	if(rsum > lsum) return rsum + lsum + sum + calc(front, r) + calc(r+1, rear);
	else return rsum + lsum + sum + calc(front, l-1) + calc(l, rear);// + calc(l, r);
	*/
}
int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d ", &cable[i]);

	printf("ans --> %d\n", calc(&cable[0], &cable[n-1]));
}
