#include <iostream>
#include <cstring>

using namespace std;
int n, m, _a, _b, _c;
int city[101][101];

void
floyd()
{
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				else if(city[i][k] != 0 && city[k][j] != 0 
						&& (city[i][j] == 0 
							|| city[i][j] > city[i][k] + city[k][j]))
						city[i][j] = city[i][k] + city[k][j];
			}
		}
	}
}

int
main()
{
	memset(city, 0, sizeof(int) * 101 * 101);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		if(city[_a][_b] == 0 || _c < city[_a][_b])
			city[_a][_b] = _c;
	}
	floyd();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("%d ", city[i][j]);
		puts("");
	}
}
