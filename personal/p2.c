#include <stdlib.h>
#include <stdio.h>


void 
quick_sort(long* x_pos, long* g_pos, int start, int end)
{
    if(end < start) return;
    long holder;
    int i = start, j = start;
    for(; j < end; j++){
        if(x_pos[j] < x_pos[end]){
            holder = x_pos[i];
            x_pos[i] = x_pos[j];
            x_pos[j] = holder;

            holder = g_pos[i];
            g_pos[i] = g_pos[j];
            g_pos[j] = holder;
            i++;
        }
    }
    holder = x_pos[i];
    x_pos[i] = x_pos[end];
    x_pos[end] = holder;

    holder = g_pos[i];
    g_pos[i] = g_pos[end];
    g_pos[end] = holder; 
    quick_sort(x_pos, g_pos, start, i - 1);
    quick_sort(x_pos, g_pos, i + 1, end);
}

void 
main()
{
    long k, x, g; // k: walking distance, n: num of building, x: building position, g: people
    int n, looper;
    long max = 0, temp_sum, *x_pos, *g_pos;
    scanf("%d %ld", &n, &k);
    x_pos = (long*)malloc(sizeof(long) * n);
    g_pos = (long*)malloc(sizeof(long) * n);

    for(int i =0; i < n; i++){
        scanf("%ld %ld", &g, &x);
        x_pos[i] = x;
        g_pos[i] = g;
    }

    quick_sort(x_pos, g_pos, 0, n-1);
    /*
    for(int i = 0; i < n; i++){
        printf("g: %2ld, x: %2ld\n", g_pos[i], x_pos[i]);
    }
    */
    max = temp_sum = g_pos[0];
    looper = 1;
    for(int i = 0; looper < n; i++){
        x_pos[i] += 2 * k;
        while(looper < n && x_pos[looper] <= x_pos[i]){
            temp_sum += g_pos[looper];
            looper++;
        }
        if(max < temp_sum) max = temp_sum;
        if(x_pos[looper] > x_pos[looper - 1] + 2 * k){
             i = looper - 1;
             temp_sum = 0;
        }
        else{
            temp_sum -= g_pos[i];
        }
    }
    printf("%ld\n", max);
}

/*
4 3
4 7
10 15
2 2
5 1
*/