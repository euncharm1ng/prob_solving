#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n, k, _a, _b
vector<pii> wv;

int
main()
{
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &_a, &_b);
		wv.push_back({_a, _b});
	}
	sort(wv.begin(), wv.end());
}
