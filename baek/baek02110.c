#include <stdio.h>
#include <stdlib.h>

int n, c, ans = 0;
int pos[200000] = {0};

int 
cmp(const void *a, const void *b) 
{ return (*(int*)a - *(int*)b); }

int 
check(int dist)
{
    int prev = pos[0], cnt = 1;
    for(int i = 1; i < n; i++){
        if(pos[i] - prev >= dist){
            cnt++; prev = pos[i];
        }   
    }   
    return cnt;
}

int
main()
{
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; i++)
        scanf("%d", &pos[i]);
    qsort(pos, n, sizeof(int), cmp);

    int low = 1, high = pos[n-1], mid;
    while(low+1 != high){
        mid = (high + low) / 2;
        if(check(mid) < c)
            high = mid;
        else
            low = mid;
    }   
    printf("%d\n", low);
}
