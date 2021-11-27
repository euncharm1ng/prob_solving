#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, _a, _b;
int parent[50000] = {0}, set[50000] = {0}, ans = 0;
vector<pair<int, int> > building;
vector<pair<int, int> > group;

inline int
dist(pair<int, int> i, pair<int, int> j)
{ return pow((i.first - j.first), 2) + pow((i.second - j.second), 2);}

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &_a, &_b);
		building.push_back(make_pair(_a, _b));
		group.push_back(make_pair(0, 0));
		parent[i] = i;
	}

	sort(building.begin(), building.end());

	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(building[j].first - building[i].first > 5) break;
			else if(dist(building[i], building[j]) <= 25){
				if(parent[j] == j){
					set[j] ^= set[i];
					parent[j] = parent[i];
					if(set[j] == 1) group[parent[j]].first++;
					else group[parent[j]].second++;
				}
				else{
					if(set[j] == set[i]){
						group[parent[j]]
					}
				}
			}
		}
	}

}
