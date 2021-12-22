#include <iostream>

using namespace std;
int matrix[1025][1025];

int main(){
    int n, m, x1, y1, x2, y2;
    int *ans;
    scanf("%d %d", &n, &m);
    for(int i =0; i< n; i++){
        matrix[0][i] = 0;
        matrix[i][0] = 0;
    }
    for(int i =1; i<= n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &matrix[i][j]);
            matrix[i][j]+= matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        }
    }

    ans = new int[m];
    for(int i=0; i< m; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ans[i] = matrix[--x1][--y1] + matrix[x2][y2] - matrix[x1][y2] - matrix[x2][y1];
    }

    // puts("matrix:");
    // for(int i =0; i <= n; i++){
    //     for(int j =0; j<=n; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     puts("");
    // }
    // puts("ans:");
    for(int i =0; i< m; i++) printf("%d\n", ans[i]);

}
