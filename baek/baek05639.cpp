#include <iostream>

using namespace std;

int n, tree[10000] = {0}, tree_size = 0;


void
postorder(int start, int end)
{

	int curr = tree[start];
	if(start+1 == end){
		printf("%d\n", curr);
		return;
	}
	for(int i = start+1; i < end; i++){
		if(tree[i] > curr){
			if(start+1 != i) postorder(start+1, i);
			postorder(i, end);
			printf("%d\n", curr);
			return;
		}
	}
	postorder(start+1, end);
	printf("%d\n", curr);
}

int 
main()
{
	while(scanf("%d", &n) == 1 && !feof(stdin)){
		tree[tree_size++] = n;
	}
	postorder(0, tree_size);
}
