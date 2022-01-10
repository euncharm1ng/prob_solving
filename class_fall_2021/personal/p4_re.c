#include <stdlib.h>
#include <stdio.h>

int cf, cg, p, q, f[2000000], g[2000000], fg[4000002];
int fpos = 0, gpos = 0, fgpos = 0, ans = 0;

void 
insert(char graph)
{
	if(graph == 'f'){
		if(f[fpos+1] > fg[fgpos+1]){
			fgpos += 2;
			fg[fgpos] = f[fpos];
			fg[fgpos+1] = f[fpos+1];
		}
		fpos += 2;
	}
	else if(graph == 'g'){
		if(g[gpos+1] > fg[fgpos+1]){
			fgpos += 2;
			fg[fgpos] = g[gpos];
			fg[fgpos+1] = g[gpos+1];
		}
		gpos += 2;
	}
}

int
do_modulo(long a, long b)
{
	return ((a % 10007) * (b % 10007)) % 10007;
}

int 
main()
{
	fg[0] = -2000000001; fg[1] = 0;
	scanf("%d", &cf);
	cf *= 2;
	for(int i = 0; i < cf; i+=2)
		scanf("%d %d", &f[i], &f[i+1]);

	scanf("%d", &cg);
	cg *= 2;
	for(int i = 0; i < cg; i+=2)
		scanf("%d %d", &g[i], &g[i+1]);

	scanf("%d %d", &p, &q);

	
	while(fpos < cf && gpos < cg){
		if(f[fpos] < g[gpos]) insert('f');
		else if(f[fpos] > g[gpos]) insert('g');
		else{
			if(f[fpos+1] > g[gpos+1]){
				insert('f');
				gpos += 2;
			}
			else{
				insert('g');
				fpos += 2;
			}
		}
	}

	if(fpos == cf){
		while(gpos < cg) insert('g');
	}
	else if(gpos == cg){
		while(fpos < cf) insert('f');
	}
	
	fgpos += 2;
	fg[fgpos] = 2000000001;
	fg[fgpos+1] = fg[fgpos-1];
	fgpos += 2;
	//for(int i = 0; i < fgpos; i+=2) printf("%d %d\n", fg[i], fg[i+1]);
	
	int currpos = 0;
	while(fg[currpos] <= p) currpos += 2;
	if(fg[currpos] > q){
		ans += do_modulo((long)q - p + 1, fg[currpos-1]);
		printf("%d\n", ans % 10007);
		return 0;
	}
	else ans += do_modulo((long)fg[currpos] - p, fg[currpos-1]);

	while(fg[currpos+2] <= q){
		ans += do_modulo((long)fg[currpos+2] - fg[currpos], fg[currpos+1]);
		ans = ans% 10007;
		currpos += 2;
	}
	ans += do_modulo((long)q - fg[currpos] + 1, fg[currpos+1]);
	printf("%d\n", ans % 10007);
}

