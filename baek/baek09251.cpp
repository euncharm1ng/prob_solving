#include <iostream>
#include <cstring>

using namespace std;

char word1[1002], word2[1002];
int len1, len2, mat[1001][1001];

int 
main()
{
	memset(mat, 0, sizeof(int) * 1001 * 1001);
	scanf("%s", word1+1);
	scanf("%s", word2+1);
	len1 = strlen(word1+1);
	len2 = strlen(word2+1);

	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(word1[i] == word2[j]) mat[i][j] = mat[i-1][j-1] + 1;
			else mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
		}
	}
	for(int i = 0; i <= len1; i++){
		for(int j = 0; j <= len2; j++){
			printf("%d ", mat[i][j]);
		}
		puts("");
	}
	printf("%d\n", mat[len1][len2]);
}
