#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct position{
	int x, y, ind;
} position;

int n, _a, _b;
vector<position> building;

bool
within_dist(pair<int, int> i, pair<int, int> j)
{
	if((pow((i.first - j.first), 2) + pow((i.second - j.second), 2)) <= 25)
		return 1;
	else return 0;
}
bool
cmp(position a, position b)
{
	if(a.x == b.x){
		return (a.y < b.y);
	}
	else return (a.x < b.x);
}

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &_a, &_b);
		building.push_back({_a, _b, i});
	}

	sort(building.begin(), building.end(), cmp);

}
