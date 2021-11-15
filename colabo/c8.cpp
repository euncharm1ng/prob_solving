#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double d_square;
vector<pair<double, double> > vill;

inline double
calc_range(int y)
{ return sqrt(d_square - y*y); }

int
main()
{
	int n, d, a, b, cnt = 1;
	double range, curr_l, curr_r;

	scanf("%d %d", &n, &d);
	d_square = d*d;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		range = calc_range(b);
		vill.push_back(make_pair(a-range, a+range));
	}

	sort(vill.begin(), vill.end());
	
	curr_r = vill[0].second;
	for(int i = 1; i < n; i++){
		if(vill[i].first > curr_r) {
			cnt++;
			curr_r = vill[i].second;
		}
		else if(vill[i].second < curr_r)
			curr_r = vill[i].second;
	}

	printf("%d\n", cnt);
}
