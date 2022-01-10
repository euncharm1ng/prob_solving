#include <iostream>
#include <cstring>

using namespace std;
int n, curr = 3, char_cnt = 6, space_cnt;
char star[3072][6144];

void
copy(int end)
{
	int from = 0, to = end/2;
	while(to != end){
		for(int i = 0; i < char_cnt; i++){
			star[to][i] = star[from][i];
			star[to][i+char_cnt] = star[from][i];
		}
		from++; to++;
	}
	char_cnt *= 2;
}

int
main()
{
	memset(star, 0, sizeof(char) * 3072 * 3072);
	star[0][0] = 1; star[1][0] = 1; star[1][2] = 1;
	for(int i = 0; i < 5; i++) star[2][i] = 1;

	scanf("%d", &n);
	while(curr != n){
		curr *= 2; copy(curr);
	}

	space_cnt = n;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++) printf(" ");
		for(int j = 0; j < space_cnt; j++){
			if(star[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
		space_cnt++;
	}
}
