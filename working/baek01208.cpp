#include <iostream>

using namespace std;

int mat[40][40];
int n, s, ans = 0;

int 
main()
{
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", &mat[0][i]);

	for(int i = 1; i < n; i++){
		for(int j = 0; j < n-i; j++){
			mat[i][j] = mat[i-1][j] + mat[0][j+i];
			if(mat[i][j] == s) ans++;
		}
	}

	printf("%d\n", ans);
	
}
