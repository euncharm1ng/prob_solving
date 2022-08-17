#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> stack;

void 
dfs(int curr, int stack_size)
{
	if(stack_size == 0){
		for(auto & iter : stack){
			cout << iter << " ";
		}
		puts("");
		return;
	}
	for(int i = curr; i <= n; i++){
		stack.push_back(i);
		dfs(i, stack_size-1);
		stack.pop_back();
	}
}

int 
main()
{
	scanf("%d %d", &n, &m);
	dfs(1, m);
}
