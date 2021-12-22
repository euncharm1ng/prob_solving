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
//거리를 확인한다
/*
* 만약 집의 좌표를 기본 어레이로 두고 이만큼 띄웠는데 공유기 설치가 가능해? 이런식으로 질문
* 거리를 high low mid. high 는 가장 큰 값 - 가장 작은 값, low는 1, mid = high + low / 2
*/