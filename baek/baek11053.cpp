#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, ansLen=0, ansNum=0;
    int arr[1000], result[1000];
    result[0] = 1; arr[0] = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    for(int i = 1; i < n; i++){
        int j=i-1, mymax=0;
        while(j>-1){
            if(arr[i]>arr[j])
                mymax = max(result[j], mymax);
            j--;
        }
        result[i] = mymax+1;
    }
    printf("%d\n", *max_element(result, result+n));
}
//  1  2  1  3  2  4
// 10 20 10 30 20 50 = 4

//  1  2  3  3  4  5
// 10 20 40 30 35 50 = 5

// 10 20 40 30 50 = 4