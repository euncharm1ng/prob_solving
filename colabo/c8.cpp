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
	int curr_l, curr_r, cnt = 1;
	scanf("%d %d", &n, &d);

	d_square = pow(d, 2);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		range = calc_range(b);
		vill.push_back(make_pair(a-range, a+range));
	}

	sort(vill.begin(), vill.end());
	for(int i = 0; i < n; i++) printf("from %d to %d\n", vill[i].first, vill[i].second);
	
	curr_l = vill[0].first; curr_r = vill[0].second;
	for(int i = 1; i < n; i++){
		if(vill[i].first > curr_r) {
			cnt++;
			curr_l = vill[i].first;
			curr_r = vill[i].second;
		}
		else if(vill[i].second < curr_r){
			curr_r = vill[i].second;
		}
	}
	printf("%d\n", cnt);
}
