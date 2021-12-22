/*special thanks to 예지 */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef unsigned long long lld;

int main(){
    clock_t t= clock();
    int arr[301];
    lld result[301];
    int n;
    scanf("%d", &n);
    for(int i =1; i<= n; i++) scanf("%d", &arr[i]);

    arr[0] = 0; result[0] =0, result[1]=arr[1], result[2] = arr[2] + arr[1];
    for(int i = 3; i<= n; i++){
        result[i] = max(arr[i-1]+result[i-3], result[i-2]) + arr[i];
    }

    printf("%lld\n", result[n]);

    t = clock() - t;
    printf("%f\n", ((float)t)/CLOCKS_PER_SEC);
}
