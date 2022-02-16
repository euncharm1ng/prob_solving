#include <iostream>
#include <cstring>

using namespace std;

int n, k, ans = 0;
char words[50][26], _str[20] = {0}, learned[26] = {0};

void
cnt_words()
{
	int exclude, cnt = 0;
	for(int i = 0; i < n; i++){
		exclude = 0;
		for(int j = 0; j < 26; j++){
			if(!learned[j] && words[i][j]){
				exclude = 1;
				break;
			}
		}
		if(!exclude) cnt++;
	}
	if(cnt > ans) ans = cnt;
}

void
teach(int ind, int cnt)
{
	learned[ind] = 1; cnt++;
	if(cnt == k) cnt_words();
	for(int i = ind; i < 26; i ++){
		if(!learned[i]) teach(i, cnt);
	}
	learned[ind] = 0;
}

int
main()
{
	memset(words, 0, sizeof(char) * 50 * 26);
	scanf("%d %d", &n, &k);
	if(k < 5) { puts("0"); return 0; }

	for(int i = 0; i < n; i++){
		scanf("%s", _str);
		for(int j = 0; j < strlen(_str); j++){
			if(!words[i][_str[j]-97]) {
				words[i][_str[j]-97] = 1;
			}
		}
	}

	learned[0] = learned[2] = learned[8] = learned[13] = learned[19] = 1;
	if(k == 5) cnt_words();
	else{
		for(int i = 1; i < 26; i++) {
			if(!learned[i]) teach(i, 5);
		}
	}
	printf("%d\n", ans);
}
