#include <iostream>
#include <algorithm>

using namespace std;
double arr[50002];
int main(){
    int n, tot;
    double avg, ans = 0, temp1, temp2;
    scanf("%d", &n);
    for(int i =1; i<=n; i++){ 
        scanf("%lf", arr+i);
        arr[i]+=arr[i-1];
    }
    avg = arr[n]/2;
    tot = (int)arr[n];

    for(int i = 0; i< n; i++){
        auto it = lower_bound(arr+i+1, arr+n, avg + arr[i]);
        //cout << ">" << arr[i] << " " << *(it-1) <<" " << *it << endl;
        temp1 = min(*it -arr[i], tot - (*it - arr[i]));
        temp2 = min(*(it-1) -arr[i], tot - (*(it-1) - arr[i]));

        ans = max(ans, max(temp1, temp2));
    }

    printf("%d\n", (int)ans);
}
