#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec;

int check(int dist){
    int prev = 0, cnt =1;
    for(int i =1; i< vec.size(); i++){
        if((vec[i] - vec[prev]) >= dist){
            prev = i;
            cnt++;
        }
    }
    cout << "--" << cnt << endl;
    return cnt;
}

int main(){
    int n, c, temp;
    
    cin >> n >> c;
    for(int i =0; i< n; i++){
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());

    int high = vec[vec.size()-1] - vec[0], low = 1, mid;
    cout << "here\n";

    while(low + 1< high){ 
        mid = (high + low) / 2;
        cout << "> " << high << " " << mid << " " << low <<  endl;
        if(c > check(mid)){
            high = mid;
            cout << "high\n";
        }
        else{
            low = mid;
            cout << "low\n";
        }
    }
    cout << low << endl;

}
