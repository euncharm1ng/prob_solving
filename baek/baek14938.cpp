#include <iostream>
#define INF 9999

using namespace std;

int n, m, r, _a, _b, _c;
int tmp_ans, ans = 0;
int map[101][101], item[101];

void 
floyed_warshall()
{
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		tmp_ans = 0;
		for(int j = 1; j <= n; j++){
			if(map[i][j] <= m) tmp_ans += item[j];
		}
		ans = max(tmp_ans, ans);
	}
}

int 
main()
{
	for(int i = 1; i < 101; i++){
		for(int j = 1; j < 101; j++){
			map[i][j] = INF;
		}
	}
	for(int i = 1; i < 101; i++) map[i][i] = 0;

	scanf("%d %d %d", &n, &m, &r);
	for(int i = 1; i <= n; i++)
		scanf("%d", &item[i]);
	for(int i = 1; i <= r; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		map[_b][_a] = map[_a][_b] = _c;
	}

	floyed_warshall();
	printf("%d\n", ans);
}
