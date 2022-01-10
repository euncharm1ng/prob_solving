#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n,ans_size = 0, start_char = -1, end_char = -1; 
int char_ind[26] = {0};
int out_degree[26] ={0}, in_degree[26] = {0}, word_cnt[26] = {0};
vector <string> dict, ans;

void
impossible()
{ puts("0"); exit(0); }

pair<int, vector<string> > // 0: append immediately, 1: append lastly
solve(int from, int to)
{
	vector<string> ret, end, mid;
	pair<int, vector<string> > recv;
	int status = 0;
	ret.push_back(dict[char_ind[from]++]);
	if(word_cnt[to] == 0){
		return {1, ret};
	}
	while(word_cnt[to] != 0){
		word_cnt[to]--;
		ans_size++;
		recv = solve(to, dict[char_ind[to]].back()-97);
		mid = recv.second;
		if(recv.first == 1){
			mid.insert(mid.end(), end.begin(), end.end());
			end = mid;
			status = 1;
		}
		else ret.insert(ret.end(), mid.begin(), mid.end());
	}
	//printf("ret size %ld, end size %ld\n", ret.size(), end.size());
	ret.insert(ret.end(), end.begin(), end.end());
	return {status, ret};
}

int
main()
{
	char _word[21];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", _word);
		dict.push_back(_word);
		out_degree[_word[0]-97]++;
		word_cnt[_word[0]-97]++;
		in_degree[_word[strlen(_word)-1]-97]++;
	}

	sort(dict.begin(), dict.end());

	for(int i = 0; i < 26; i++){
		if(out_degree[i] == in_degree[i]);
		else if(out_degree[i] == in_degree[i]+1){
			if(start_char != -1) impossible();
			else start_char = i;
		}
		else if(out_degree[i]+1 == in_degree[i]){
			if(end_char != -1) impossible();
			else end_char = i;
		}
		else impossible();
	}

	if(start_char == -1){
		start_char = 0;
		end_char = 0;
	}

	int prev = -1;
	for(int i = 0; i < n; i++){
		if(dict[i][0]-97 != prev){
			prev = dict[i][0]-97;
			char_ind[prev] = i;
		}
	}
	word_cnt[start_char]--;
	ans_size++;
	pair<int, vector<string> > recv = solve(start_char, dict[char_ind[start_char]].back()-97);
	ans = recv.second;

	//printf("%d %d %ld\n", n, ans_size, ans.size());
	if(ans_size == n)
		for(int i = 0; i < ans_size; i++) cout << ans[i] << "\n";
	else impossible();
}
