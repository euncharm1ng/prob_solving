#include <iostream>

using namespace std;

int friendship[1001][1001];
int inssa = 0;

int 
main()
{
	memset(friendship, 0, sizeof(int)*1001*1001);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &_a, &_b);
		if(_a < _b) friendship[_a][_b] = 1;
		else friendship[_b][_a] = 1;
	}

	for(int i = 0; i < n; i++){

	}
}
