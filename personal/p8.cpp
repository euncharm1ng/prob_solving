#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, t;
ll max_dist;
vector<pair<int, ll> > folks;

int
main()
{
	int a; 
	ll b;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++){
		scanf("%d %lld", &a, &b);
		folks.push_back({a, b * t + a});
	}

	sort(folks.begin(), folks.end(), greater<>());

/*
	for(int i = 0; i < n; i++){
		printf("%d %lld\n", folks[i].first, folks[i].second);
	}
*/

	max_dist = folks[0].second;
	for(int i = 1; i < n; i++){
		if(folks[i].second >= max_dist) n--;
		else max_dist = folks[i].second;
	}

	//printf("ans --> %d\n", n);
	printf("%d\n", n);
}


//1000000000 == 10^9
//1000000000000000000
