#include <iostream>
#include <cstring>

using namespace std;
#define MOD 1000

long long b;
int is_odd = 0, curr = 0, prevv = 1, n;
int mat[2][5][5];

void
toggle()
{ 
	prevv = curr; curr ^= 1; 
	memset(mat[curr], 0, sizeof(int) * 5 * 5);
}

void 
mult(int tar[5][5])
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++)
				mat[curr][i][j] += tar[i][k] * mat[prevv][k][j];
			mat[curr][i][j] %= MOD;
		}
	}
}

void
calc()
{
	int temp[5][5];
	while(b > 1){
		if(b % 2){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++)
					temp[i][j] = mat[curr][i][j];
			}
			b--;
			calc();
			toggle();
			mult(temp);
			return;
		}
		b /= 2;
		toggle();
		mult(mat[prevv]);
	}
}

int
main()
{
	memset(mat, 0, sizeof(int) * 2 * 5 * 5);
	scanf("%d %lld", &n, &b);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &mat[curr][i][j]);
		}
	}
	calc();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ", mat[curr][i][j] % MOD);
		puts("");
	}
}
