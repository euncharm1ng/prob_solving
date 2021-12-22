#include <iostream>

using namespace std;

int ukl(int a, int b){
    if(b==0) return a;
    return ukl(b, a%b);
}

int main(){
    int x, y;
    cin >> x >> y;
    cout << x + y - ukl(x,y) <<endl;
}
