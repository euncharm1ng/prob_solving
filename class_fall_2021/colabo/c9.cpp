#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int 
main()
{
	int a, b, n, group[8000] = {0}, ans = 0;
	vector<pair<int, int> > applicant;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		applicant.push_back(make_pair(a, b));
		group[i] = i;
	}

	sort(applicant.begin(), applicant.end());
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(applicant[j].second < applicant[i].second){
				if(group[j] != j) group[i] = group[j];
				else group[j] = group[i];
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		if(group[i] == i) ans++;
	}

	printf("%d\n", ans);
}
