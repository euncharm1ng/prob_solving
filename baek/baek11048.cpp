#include <iostream>

using namespace std;

int maze[1001][1001];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) maze[i][0] =0;
    for(int i=0; i<m; i++) maze[0][i] =0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){ 
            scanf("%d", &maze[i][j]);
            maze[i][j]+=max(maze[i-1][j], max(maze[i][j-1], maze[i-1][j-1]));
        }
    }
    printf("%d\n", maze[n][m]);

}