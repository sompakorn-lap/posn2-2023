#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int A[N][N];

int main(){
    int n, m, q;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            scanf("%d", &A[i][j]);
            A[i][j] = A[i][j] + A[i][j-1] + A[i-1][j] - A[i-1][j-1];
        }
    }
    scanf("%d", &q);
    while(q--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", A[x2][y2] - A[x2][y1-1] - A[x1-1][y2] + A[x1-1][y1-1]);
    }
    return 0;
}