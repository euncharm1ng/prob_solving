#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int input[8];
vector<int> stack;

void 
backtrack(int curr, int len){
	if(len == m){
		for(auto & iter : stack)
			cout << iter << " ";
		puts("");
		return;
	}
	for(int i = curr; i < n; i++){
		stack.push_back(input[i]);
		backtrack(i, len+1);
		stack.pop_back();
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
		stack.push_back(input[i]);
		backtrack(i, 1);
		stack.pop_back();
	}
}
