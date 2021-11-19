#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int 
main()
{
	int a, b, n;
	vector<pair<int, int> > applicant;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		applicant.push_back({a, b});
	}

	sort(applicant.begin(), applicant.end());
	
	for(int i = 0; i < n; i++) printf("%d %d\n", applicant[i].first, applicant[i].second);

	int smaller = 0, ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(applicant[j].second < applicant[i].second) ans++;
		}
	}
	printf("ans --> %d\n", ans);
}
