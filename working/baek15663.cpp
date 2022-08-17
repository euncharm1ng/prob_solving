#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int input[8], visit[8] = {0};

vector<int> stack;

void 
backtrack(int curr, int len){
	if(len == m){
		for(auto & iter : stack)
			cout << iter << " ";
		puts("");
		return;
	}
	for(int i = 0; i < n; i++){
		if(visit[i] == 0 && (i != 0 && input[i] != input[i-1])){
			stack.push_back(input[i]); visit[i] = 1;
			backtrack(i, len+1);
			stack.pop_back(); visit[i] = 0;
		}
	}
}

int 
main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &input[i]);

	sort(&input[0], &input[n]);

	for(int i = 0; i < n; i++){
		if(i == 0 || input[i] != input[i-1]){
			stack.push_back(input[i]); visit[i] = 1;
			backtrack(i, 1);
			stack.pop_back(); visit[i] = 0;
		}
	}
}
