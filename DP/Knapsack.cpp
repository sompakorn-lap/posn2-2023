#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 505;
const int K = 1e5+5;
int dp[N][K];
pii wv[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &wv[i].first, &wv[i].second);
    }
    int w, v;
    for(int i=1; i<=n; ++i){
        tie(w, v) = wv[i];
        for(int j=0; j<=k; ++j){
            if(j < w) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v);
        }
    }
    printf("%d", dp[n][k]);
    return 0;
}