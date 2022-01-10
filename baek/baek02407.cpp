#include <iostream>

using namespace std;
#define INF 100000000000000000
typedef long long ll;
typedef pair<ll, ll> plll;

plll number[101][101];
int n, m;
ll prev_fir, prev_sec, next_fir, next_sec;

int 
main()
{
	scanf("%d %d", &n, &m);
	number[0][0] = {0, 1};
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(j-1 < 0) prev_fir = 0, prev_sec = 0;
			else prev_fir = number[i-1][j-1].first, prev_sec = number[i-1][j-1].second;
			if(j > i-1) next_fir = 0, next_sec = 0;
			else next_fir = number[i-1][j].first, next_sec = number[i-1][j].second;
			number[i][j].second = prev_sec + next_sec;
			number[i][j].first = prev_fir + next_fir + number[i][j].second / INF;
			number[i][j].second %= INF;
		}
	}
	if(number[n][m].first != 0) printf("%lld", number[n][m].first);
	printf("%lld\n", number[n][m].second);
}
