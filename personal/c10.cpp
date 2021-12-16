#include <iostream>
#include <vector>

using namespace std;

int n;
char words[1000][20];
vector<pair<char, char> > dictionary;
int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", words[i]);
		dictionary.push_back(make_pair(words[i][0], words[i][strlen(words[i])-1]));
	}
	for(int i = 0; i < n; i++){
		printf("%s %c %c\n", words[i], dictionary[i].first, dictionary[i].second);
	
	}
}

