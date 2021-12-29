#include <iostream>
#include <cstring>

using namespace std;
#define INF 1e10


int n, e, _a, _b, _c, v1, v2;
int graph[801][801];

int 
main()
{
	memset(graph, -1, sizeof(int) * 801 * 801);
	scanf("%d %d", &n, &e);
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &_a, &_b, &_c);
		graph[_a][_b] = _c;
		graph[_b][_a] = _c;
	}
	scanf("%d %d", &v1, &v1);
}
