#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n, start_char = 0, end_char = 0;
vector <string> dict;
vector <pair<int, int> > occurence(26, {0, 0});

int
main()
{
	char _word[21];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", _word);
		dict.push_back(_word);
		occurence[_word[0] - 97].first++;
		occurence[_word[strlen(_word)-1] - 97].second++;
	}

	for(int i = 0; i < 26; i++){
		if(occurence[i].first > occurence[i].second){
			if(start_char != 0){
				puts("0"); return 0;
			}
			else start_char = i;
		}
		else if(occurence[i].first < occurence[i].second){
			if(end_char != 0){
				puts("0"); return 0;
			}
			else end_char = i;
		}
		printf("%c %d %d\n", i+97, occurence[i].first, occurence[i].second);
	}

	sort(dict.begin(), dict.end());

	for(int i = 0; i < n; i++){
		cout << dict[i] << endl;
	}
}
