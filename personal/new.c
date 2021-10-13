#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
typedef long long ll;

ll f_start[1000000], all_start[2000001];
ull f_value[1000000], all_value[2000001];
int all_pos = 0, f_pos = 0;

void
push(ll start, ull value)
{
	all_start[all_pos] = start;
	all_value[all_pos] = value;
	all_pos++;
}

int
main()
{
	int f, g, q, p, start_in, value_in;
	ull ans = 0;
	scanf("%d", &f);
	for(int i = 0; i < f; i++){
		scanf("%d %d", &start_in, &value_in);
		f_start[i] = start_in;
		f_value[i] = value_in;
	}
	scanf("%d", &g);
	for(int i = 0; i < g; i++){
		scanf("%d %d", &start_in, &value_in);
		while(f_pos < f && f_start[f_pos] < start_in){
			push(f_start[f_pos], f_value[f_pos]);
			f_pos++;
		}
		if(f_pos < f && f_start[f_pos] == start_in){
			if(f_value[f_pos] > value_in) push(start_in, f_value[f_pos]);
			else push(start_in, value_in);
			f_pos++;
		}
		else if(value_in > f_value[f_pos - 1]){
			push(start_in, value_in);
			while(f_pos < f && f_value[f_pos] <= value_in) f_pos++;
		}
	}
	for(int i = f_pos; i < f; i++){
		push(f_start[i], f_value[i]);
	}

	scanf("%d %d", &p, &q);
/*	
	printf("pq:: %d %d\n", p, q);
	for(int i = 0; i < all_pos; i++){
		printf("%lld %lld\n", all_start[i], all_value[i]);
	}
*/
	all_pos--;

	if(q < all_start[0]) ans = 0;
	else if(p > all_start[all_pos]) ans = (((ll)q - p + 1) * all_value[all_pos]);
	else{
		while(q < all_start[all_pos]) all_pos--;
		if(p > all_start[all_pos]){
			ans += (((ll)q - p + 1) * all_value[all_pos]) ;
		}
		else{
			ans += (((ll)q - all_start[all_pos] + 1) * all_value[all_pos]);
			all_pos--;
			while(all_pos > -1 && p < all_start[all_pos]){
				ans += ((all_start[all_pos + 1] - all_start[all_pos]) * all_value[all_pos]);
				all_pos--;
			}
			if(all_pos != -1) 
				ans += ((all_start[all_pos + 1] - p) * all_value[all_pos]);
		}
	}
	printf("%lld\n", ans % 10007);
}
