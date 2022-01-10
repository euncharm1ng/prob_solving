#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int
main()
{
	int a, ans, n, t;
	ll b, max_dist;
	vector<pair<int, ll> > folks;

	scanf("%d %d", &n, &t);
	ans = n;

	for(int i = 0; i < n; i++){
		scanf("%d %lld", &a, &b);
		folks.push_back({a, b*t+a});
	}

	sort(folks.begin(), folks.end(), greater<>());

	max_dist = folks[0].second;
	for(int i = 1; i < n; i++){
		if(folks[i].second >= max_dist) ans--;
		else max_dist = folks[i].second;
	}

	printf("%d\n", ans);
}
