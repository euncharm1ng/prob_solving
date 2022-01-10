//y dir and x dir? --> nlgn
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, _a, _b;
vector<pair<int, int> > building;
int oppo[500000], parent[500000], child_cnt[500000];

bool
within_dist(pair<int, int> i, pair<int, int> j)
{
	if((pow((i.first - j.first), 2) + pow((i.second - j.second), 2)) <= 25)
		return true;
	else return false;
}

int find_ancestor(int x)
{ 
	if(parent[x] == x) return x;
	else return parent[x] = find_ancestor(parent[x]);
}

void
do_union(int x, int y)
{
	parent[x] = find_ancestor(parent[x]);
	oppo[y] = find_ancestor(oppo[y]);

	if(parent[x] == oppo[y]);
	else if(parent[x] > oppo[y]){
		child_cnt[oppo[y]] += child_cnt[parent[x]];
		child_cnt[parent[x]] = 0;
		parent[x] = oppo[y];
	}
	else{
		child_cnt[parent[x]] += child_cnt[oppo[y]];
		child_cnt[oppo[y]] = 0;
		oppo[y] = parent[x];
	}
	oppo[x] = oppo[parent[x]];
}



int
main()
{
	fill_n(child_cnt, 500000, 1);
	int ans = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &_a, &_b);
		building.push_back({_a, _b});
		oppo[i] = parent[i] = i;
	}

	sort(building.begin(), building.end());

	for(int i = 0; i < n; i++){
		for(int j = i+1; j<n; j++){
			if(building[i].first+5 < building[j].first) break;
			else if(within_dist(building[i], building[j])){
				if(oppo[i] == i && oppo[j] == j){
					oppo[j] = i; oppo[i] = j;
				}
				else{
					if(oppo[i] != i) do_union(j, i);
					if(oppo[j] != j) do_union(i, j);
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(oppo[i] == i) continue;
		else if(parent[i] == i){
			oppo[i] = find_ancestor(oppo[i]);
			ans+= (child_cnt[oppo[i]] > child_cnt[i])? child_cnt[i] : child_cnt[oppo[i]];
			parent[oppo[i]] = i;
		}
	}
	printf("%d\n", ans);
}
