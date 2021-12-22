#include <iostream>

using namespace std;

int main(){
    int n, ans;
    scanf("%d", &n);
    int* arr = new int[n]();
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    ans = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i-1]>0) arr[i]+=arr[i-1];
        ans = max(ans, arr[i]);
    }
    printf("%d\n", ans);
}
