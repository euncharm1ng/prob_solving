#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int n, d, d_square;
vector<pair<int, int> > vill;

inline int
calc_range(int y)
{ return sqrt(d_square - pow(y, 2)); }

int
main()
{
	int a, b, range;
	scanf("%d %d", &n, &d);
	d_square = pow(d, 2);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		range = calc_range(b);
		vill.push_back(make_pair(a-range, a+range));
	}

	for(int i = 0; i < n; i++){
		printf("from %d to %d\n", vill[i].first, vill[i].second);
	}
}
