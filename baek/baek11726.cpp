#include <iostream>
#include <cstring>

using namespace std;
typedef unsigned long long  lld;
lld arr[1001];

lld f(int n){
    if(n < 2) return arr[n] = 1;

    lld& ret = arr[n];
    if(ret != -1) return ret;

    return ret = (f(n-1) + f(n-2))%10007;
}
int main(){
   // clock_t t = clock();
    int n ;
    scanf("%d", &n);
    memset(arr, -1, sizeof(arr));

    printf("%lld\n", f(n));
    //t = clock() -t;
    //printf("%f\n", ((float)t)/CLOCKS_PER_SEC);
}