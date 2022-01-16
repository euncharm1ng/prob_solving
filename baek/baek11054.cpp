#include <iostream>

using namespace std;

int n, max_size = 0, ans = -1;
int num[1000] = {0}, inc_cnt[1000] = {0}, lis_max[1000] = {0};

void
calc(int curr, int curr_ind)
{
        int left = -1, right = max_size, mid;
        while(left+1 != right){
                mid = (left + right) / 2;
                if(lis_max[mid] < curr) left = mid;
                else right = mid;
        }
        lis_max[right] = curr;
        inc_cnt[curr_ind] += right;
        if(right == max_size) max_size++;
}

int
main()
{
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
                scanf("%d", &num[i]);
        for(int i = 0; i < n; i++)
                calc(num[i], i);
        max_size = 0;
        for(int i = n-1; i >= 0; i--)
                calc(num[i], i);

        for(int i = 0; i < n; i++){
                if(inc_cnt[i] > ans) ans = inc_cnt[i];
        }
        printf("%d\n", ans+1);
}
