#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n, k, turn[100001], cnt[100001];
queue<int> Q;

inline int
calc(int src, int dest)
{
	if(dest > 100000 || dest < 0) return 0;
	if(turn[dest] == -1){
		turn[dest] = turn[src] + 1;
		cnt[dest] = cnt[src];
		return 1;
	}
	else if(turn[dest] == turn[src] + 1){
		cnt[dest] += cnt[src];
		return 0;
	}
	return 0;
}

void 
BFS()
{
	int curr, elap;
	turn[n] = 0; cnt[n] = 1; Q.push(n);

	while(turn[k] == -1){
		curr = Q.front(); Q.pop();
		if(calc(curr, curr-1)) Q.push(curr-1);
		if(calc(curr, curr+1)) Q.push(curr+1);
		if(calc(curr, curr*2)) Q.push(curr*2);
	}

	elap = turn[k]-1, cnt[k] = 0;
	if(k > 0 && elap == turn[k-1]) cnt[k] += cnt[k-1];
	if(k < 100000 && elap == turn[k+1]) cnt[k] += cnt[k+1];
	if(k != 0 && (!(k % 2) && elap == turn[k/2])) cnt[k] += cnt[k/2];
}

int
main()
{
	memset(turn, -1, sizeof(int) * 100001);
	memset(cnt, -1, sizeof(int) * 100001);
	scanf("%d %d", &n, &k);

	if(k < n){
		printf("%d\n1\n", n - k); return 0;
	}
	else if(k == n){
		puts("0\n1"); return 0;
	}

	BFS();
	printf("%d\n%d\n", turn[k], cnt[k]);
}
