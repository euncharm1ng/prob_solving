#include <iostream>
using namespace std;

long long doit(long long a, int b, int c){
    if(b==1) return a%c;
    if(b%2) return (doit( (a%c*a%c), b/2, c)  * a%c) %c;
    return doit((a%c*a%c), b/2, c)%c;
}


int main(){
    clock_t t = clock();
    unsigned long long a, remainder, product =1;
    int b, c;
    scanf("%lld %d %d", &a, &b, &c);

    printf("%lld\n", doit(a, b, c));
    t = clock() -t;
    printf("%f\n", ((float)t)/CLOCKS_PER_SEC);
}
/*
(a * a * a) % c = ((a % c) * (a % c) * (a % c)) % c

    = ((a % c) * (a * a) % c) % c
    = ((a % c) * ((a % c) * (a % c) % c) % c) % c

(a^5)%c = ((a^2)%c * (a^2)%c * a%c)%c
(a^4)%c = ((a^2)%c * (a^2)%c )%c

(a^4)%c = ( (a%c * a%c) %c *  (a%c * a%c) %c )%c

(a^2)%c = (a%c * a%c) %c


2147483647

*/
