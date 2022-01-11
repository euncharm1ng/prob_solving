#include <iostream>

using namespace std;

int n, _a, ans_size = 0;;
int ans[1000] = {0};

int
main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &_a);
		for(int j = 0; j <= ans_size; j++){
			if(ans[j] == 0){
				ans[j] = _a;
				ans_size++;
				break;
			}
			else if(_a > ans[j]);
			else{
				ans[j] = _a;
				break;
			}
		}
	}
	printf("%d\n", ans_size);
}
