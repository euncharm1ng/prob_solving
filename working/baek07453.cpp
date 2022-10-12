#include <iostream>

using namespace std;

int arr[4000][4];
int n;

int 
main()
{
	scanf("%d ", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d ", &arr[i][0], &arr[i][1],&arr[i][2],&arr[i][3]);
	}
}
