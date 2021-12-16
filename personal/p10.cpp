#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

typedef struct alpha{
	int front, rear;
	int back_to_back, ind;
} alpha;

int n, start_word = -1, last_word = -1;
vector <pair<string, int> > dict;
vector <alpha> info(26, {0,0,0,0});

int
is_impossible()
{
	int _add_next = 0;
	for(int i = 0; i < 26; i++){
		info[i].ind = _add_next;
		_add_next += info[i].front;
		if(info[i].front > info[i].rear){
			if(info[i].front != info[i].rear+1 || start_word != -1){
				puts("0"); return 1;
			}
			start_word = i;
		}
		else if(info[i].front < info[i].rear){
			if(info[i].front+1 != info[i].rear || last_word != -1){
				puts("0"); return 1;
			}
			last_word = i;
		}
		else if(info[i].front == info[i].back_to_back && info[i].front != 0){
			puts("0"); return 1;
		}
	}
	if(start_word == -1) start_word = 0;
	return 0;
}

void
print_ans(int curr)
{
	if(info[curr].front == 0) return;
	int next = dict[info[curr].ind].second;
	int curr_word = info[curr].ind++;
	info[curr].front--;
	info[next].rear--;
	if(next == curr) info[curr].back_to_back--;
	if(info[next].front == 0 && info[curr].front != 0){
		print_ans(dict[info[curr].ind+1].second);
	}
	if(info[curr].front == info[curr].back_to_back && info[curr].rear == info[curr].front){
		for(int i = 0; i < info[curr].back_to_back; i++){
			cout << dict[info[curr].ind+i].first << "\n";
		}
	}
	cout << dict[curr_word].first << "\n";
	print_ans(next);
}

int
main()
{
	char _word[21];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", _word);
		dict.push_back({_word, _word[strlen(_word)-1] - 97});
	}
	sort(dict.begin(), dict.end());

	for(int i = 0; i < n; i++){
		info[dict[i].first[0]-97].front++;
		info[dict[i].second].rear++;
		if(dict[i].first[0]-97 == dict[i].second){
			info[dict[i].second].back_to_back++;
		}
	}

	if(is_impossible()) return 0;
	print_ans(start_word);
}

