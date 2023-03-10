#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[1<<8];

int main(){
    int n, k;
    int v, x, b;
    fill(dp, dp+(1<<8), 1e9+7);
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i){
        scanf("%d", &v);
        x = 0;
        for(int j=0; j<k; ++j){
            scanf("%d", &b);
            x = x | (b<<j);
        }
        dp[x] = min(dp[x], v);
    }
    for(int i=0; i<(1<<k); ++i){
        for(int j=0; j<(1<<k); ++j){
            dp[i|j] = min(dp[i|j], dp[i]+dp[j]);
        }
    }
    printf("%d", dp[(1<<k)-1]);
    return 0;
}