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
vectoc <string> last_words;

void
impossible()
{ puts("0"); exit(0); }


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
		//if(out_degree[i] != 0) printf("%c %d %d\n", i+97, out_degree[i], in_degree[i]);
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
		//cout << dict[i] << endl;
	}
	/*
	for(int i = 0; i < 26; i++) 
		if(char_ind[i]!=0)printf("%c start %d\n", i+97, char_ind[i]);
	for(int i = 0; i < 26; i++)
		if(word_cnt[i] != 0) printf("word cnt: %c %d\n", i+97, word_cnt[i]);
	*/

	//printf("start : %d end : %d \n", start_char, end_char);
	int pos = start_char;
	while(word_cnt[pos] != 0){
		int next_pos = dict[char_ind[pos]].back()-97;
		in_degree[next_pos]--;
		if(in_degree[next_pos] == 0 && word_cnt[pos] != 1){
			last_words.push_back(dict[char_ind[pos]++]);
			word_cnt[pos]--;
			ans_size++;
			next_pos = dict[char_ind[pos]].back()-97;
		}
		ans.push_back(dict[char_ind[pos]++]);
		word_cnt[pos]--;
		ans_size++;
		pos = next_pos;
	}
	if(!last_word.empty()) ans.push_back(last_word);

	printf("ans size: %d, n: %d\n", ans_size, n);
	for(int i = 0; i < ans_size; i++) cout << ans[i] << endl;

	if(ans_size == n)
		for(int i = 0; i < ans_size; i++) cout << ans[i] << endl;
	else impossible();
}
