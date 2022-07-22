#include <iostream>

using namespace std;

int n, m, map[8][8];

int 
main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%d ", map[i][j]);
		}
		puts("");
	}
}
