#include <iostream>
#include <stack>

using namespace std;
int inorder[100000] = {0}, postorder[100000] = {0};
int n, root_ind;
stack<int> ans;

void
do_preorder(int start, int end) // root, left, right
{
	root_ind--;
	if(start+1 >= end) {
		ans.push(postorder[root_ind]);
		return;
	}

	int root = postorder[root_ind];
	for(int i = start; i < end; i++){
		if(inorder[i] == root){
			if(i+1 < end) do_preorder(i+1, end);
			if(start < i) do_preorder(start, i);
			break;
		}
	}
	ans.push(root);
}

int 
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &inorder[i]); // left, root, right
	for(int i = 0; i < n; i++)
		scanf("%d", &postorder[i]); // left, right, root
	root_ind = n;
	do_preorder(0, n);
	while(!ans.empty()){
		cout << ans.top() << " ";
		ans.pop();
	}
	puts("");
}
