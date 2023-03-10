#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9+7;
int dp[N][N];
int R[N], C[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d %d", &R[i], &C[i]);
    
    for(int sz=1; sz<=n; ++sz){
        for(int l=0, r=sz-1; r<n; ++l, ++r){
            if(l-r+1 == 1){
                dp[l][r] = 0;
            }
            else {
                int tmp = INF;
                for(int m=l; m<=r-1; ++m){
                    tmp = min(tmp, dp[l][m]+dp[m+1][r]+R[l]*C[m]*C[r]);
                }
                dp[l][r] = tmp;
            }
        }
    }
    printf("%d", dp[0][n-1]);
    return 0;
}