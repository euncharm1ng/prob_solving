#include <iostream>

using namespace std;

typedef pair<string, int> inputPair;

int main(){
    int m, n, b, dir;
    string a;
    inputPair input[n];
    pair<int, int> loc;

    cin >> m >> n;
    for(int i =0; i< n; i++){
        cin >> a >> b;
        input[i] = pair<string, int>(a, b);
    }
    // ------------ calculation -----------
    loc.first = 0; // x coor
    loc.second = 0; // y coor
    dir = 0; // 0 == right, 1 == bot, 2 == left, 3 == top
    for(int i =0; i< n; i++){
        if(input[i].first == "TURN"){
            if(input[i].second == 0){
                dir--; 
                if(dir<0) dir = 3;
            }
            else if(input[i].second == 1){
                dir++;
                if(dir>3) dir = 0;
            }
            else{
                cout << "input error 1" << endl;
                return 1;
            }
        }
        else if(input[i].first == "MOVE"){
            if(dir == 0){ // to right
                loc.first += input[i].second;
                if(loc.first > m){
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else if(dir == 1){ // to bot
                loc.second -= input[i].second;
                if(loc.second < 0){
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else if(dir == 2){ // to left 
                loc.first -= input[i].second;
                if(loc.first < 0){
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else if(dir == 3){ // to top
                loc.second += input[i].second;
                if(loc.second > m){
                    cout << "-1" << endl;
                    return 0;
                }
            }
            else{
                cout << "input error 2" << endl;
                return 1;
            }
        }
        else cout << "fail fail" << endl;
    } //end of for for moving robot

    cout << loc.first << " " << loc.second << endl;
}
