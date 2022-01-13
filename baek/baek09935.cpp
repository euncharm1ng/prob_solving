#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int , int> pii;

char str[1000001], keyword[37];
int ind, chkr = -1, str_len, key_len, printed = 0;
vector<pii> skip;

int
try_match()
{
	int i, start = ind;
	for(i = 0; i < key_len && ind < str_len; i++, ind++){
		if(str[ind] == keyword[i]);
		else if(str[ind] == keyword[0]){
			if(try_match() == 0) return 0;
			else i--; 
		}
		else return 0;
	}
	if(ind == str_len && i != key_len) return 0;
	skip.push_back({start, --ind});
	return ind + 1;
}

int
main()
{
	scanf("%s %s", str, keyword);
	str_len = strlen(str); key_len = strlen(keyword);

	for(ind = 0; ind < str_len; ind++){
		if(str[ind] == keyword[0]) try_match();
	}

	sort(skip.begin(), skip.end());
	
	for(auto itr : skip){
		if(itr.second > chkr){
			for(int i = itr.first; i <= itr.second; i++)
				str[i] = '*';
			chkr = itr.second;
		}
	}

	for(int i = 0; i < str_len; i++){
		if(str[i] == '*');
		else{
			printf("%c", str[i]);
			printed = 1;
		}
	}
	if(!printed) puts("FRULA");
	else puts("");
}
