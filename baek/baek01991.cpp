#include <iostream>
#include <vector>

using namespace std;
typedef struct node{
	int left, right;
} node;

int n;
char _a, _b, _c;
vector<node> tree(26, {-1, -1});

void 
preorder(int curr){
	printf("%c", curr+65);
	if(tree[curr].left != -1) preorder(tree[curr].left);
	if(tree[curr].right != -1) preorder(tree[curr].right);
}

void 
inorder(int curr){
	if(tree[curr].left != -1) inorder(tree[curr].left);
	printf("%c", curr+65);
	if(tree[curr].right != -1) inorder(tree[curr].right);
}

void 
postorder(int curr){
	if(tree[curr].left != -1) postorder(tree[curr].left);
	if(tree[curr].right != -1) postorder(tree[curr].right);
	printf("%c", curr+65);
}
int 
main()
{
	scanf("%d ", &n);
	for(int i = 0; i < n; i++){
		scanf("%c %c %c ", &_a, &_b, &_c);
		if(_b < 65 || _b > 90) tree[_a-65].left = -1;
		else tree[_a-65].left = _b - 65;
		if(_c < 65 || _c > 90) tree[_a-65].right = -1;
		else tree[_a-65].right = _c - 65;
	}
	preorder(0);
	puts("");
	inorder(0);
	puts("");
	postorder(0);
	puts("");
}
