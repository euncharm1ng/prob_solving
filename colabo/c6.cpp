#include <iostream>
using namespace::std;

int n;
int card[50000], up[50000] ={0}, down[50000]={0}, upV[50000] = {0}, downV[50000] = {0};

void
calc(int start, int dir)
{
	int end = n, *arr = up, *val = upV, range = 1, chkr = 0;
	if(start != 0){
		end = -1; arr = down; val = downV;
	}
	arr[0] = card[start];
	for(int i = start + dir; i != end; i += dir){
		for(int j = 0; j < range; j++){
			if(arr[j] >= card[i]){
				arr[j] = card[i];
				val[i] = j;
				chkr = 1;
				break;
			}
		}
		if(!chkr){
			arr[range] = card[i];
			val[i] = range;
			range++;
		}
		else chkr = 0;
	}
}

int
main()
{
	int ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &card[i]);
	calc(0, 1);
	calc(n-1, -1);
	for(int i = 0; i < n; i++){
		if(upV[i] + downV[i] + 1 > ans) ans = upV[i] + downV[i] + 1;
	}
	printf("%d\n", ans);
}
