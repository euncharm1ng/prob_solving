#include <iostream>
using namespace std;

int main(){
    long long sum =0;
    int N, M, temp;
    long long cnt =0;
    int *exist;
    
    scanf("%d %d", &N, &M);
    exist = new int[M]();
    exist[0] = 1;

    for(int i =0; i<N; i++){
        scanf("%d", &temp);
        sum += temp;
        temp = sum%M;
        cnt+= exist[temp]++;
    }
    cout << cnt << endl;
}

/*
#include <cstdio>
#include <unistd.h>
#define sz (1<<20)
#define f(x) {x=0;while(1){if(c==e)syscall(0,0,c=s,sz);if(*c>='0')break;c++;}while(1){if(c==e)syscall(0,0,c=s,sz);if(*c<'0')break;x=x*10+*c++-'0';}}
int main() {
	unsigned char s[sz],*c,*e;c=e=s+sz;
	unsigned a[1000]{}, n, k; unsigned long r=0; f(n); f(k);
	for(int x=0, t; n--; r+=a[x=(x+t)%k]++) f(t);
	printf("%lu\n", r+a[0]);
}
*/