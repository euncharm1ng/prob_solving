#include <iostream>
using namespace::std;

int n, cost[500][500] = {0}, cable[500];

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d ", &cable[i]);
	for(int i = 0; i < n-1; i++) cost[i+1][i] = cost[i][i+1] = cable[i] + cable[i+1];
	
	for(int i = 2; i < n; i++){
		for(int j = 0; j < n - i; j++){
			cost[j][j+i] = 	cost[j][j] + cost[j+1][j+i];
			for(int k = 1; k < i; k++){
				int temp = cost[j][j+k] + cost[j+k+1][j+i];
				if(temp < cost[j][j+i]) cost[j][j+i] = temp;
			}
			cost[j][j+i] += cost[j+i][j] = cost[j+i-1][j] + cable[j+i];
		}
	}

	printf("%d\n", cost[0][n-1]);
}
