#include <iostream>

using namespace std;

int parent[500000];

int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return 1;
    parent[u]=v;
    return 0;
}

int main(){
    int n, m, a, b, ans =0;
    scanf("%d %d", &n, &m);
    for(int i=0; i< n; i++) parent[i] = i;

    for(int i =0; i< m; i++){
        scanf("%d %d", &a, &b);
        if(merge(a,b)){ ans=i+1; break;}
    }
    printf("%d\n", ans);
}