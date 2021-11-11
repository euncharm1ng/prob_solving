#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, d;
vector<pair<int, int> > vill;

int
main()
{
	int a, b;
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		vill.push_back({a, b});
	}
}
