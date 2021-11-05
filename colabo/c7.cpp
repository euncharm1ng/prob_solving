#include <iostream>
#include <vector>
#include <cstring>

#define BLACK 1
#define RED 2

using namespace::std;

int n, m, a, b;
int redblack[10001] = {0}, chkr[10001] = {0};
vector<vector<int> > neighbors;

inline int
get_oppo(int color)
{ return (color == RED)? BLACK : RED; }

int
try_change(int ind, int change_to)
{
	redblack[ind] = change_to;
	int neighbor_to = get_oppo(change_to);
	for(int i = 1; i < neighbors[ind].size(); i++){
		if(redblack[neighbors[ind][i]] == neighbor_to) continue;
		else if(chkr[neighbors[ind][i]]) return 1;
		else{
			chkr[neighbors[ind][i]] = 1;
			if(try_change(neighbors[ind][i], neighbor_to)) return 1;
		}
	}
	return 0;
}

int
mark_redblack(int ind1, int ind2)
{
	if(!redblack[ind1] && !redblack[ind2]){
		redblack[ind1] = RED;
		redblack[ind2] = BLACK;
	}
	else if(!redblack[ind1]){
		redblack[ind1] = get_oppo(redblack[ind2]);
	}
	else if(!redblack[ind2]){
		redblack[ind2] = get_oppo(redblack[ind1]);
	}
	else if(redblack[ind1] == redblack[ind2]){
		chkr[ind2] = 1;
		if(try_change(ind1, get_oppo(redblack[ind1]))) return 1;
		memset(chkr, 0, sizeof(int) * (n+1));
	}
	return 0;
}

int 
main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n+1; i++) neighbors.push_back({0});
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		neighbors[a].push_back(b);
		neighbors[b].push_back(a);
		if(mark_redblack(a, b)){ printf("%d\n", i+1); return 0;}
	}
}
