#include <bits/stdc++.h>
using namespace std;

const int K = 1e5+5;
const int INF = 1e9+7;
int dp1[K], n, c[500], dp2[K];

int solve(int k){
    if(k == 0) return 0;

    if(dp1[k] != INF) return dp1[k];

    int tmp = INF;
    for(int i=0; i<n; ++i){
        if(c[i] > k) continue;
        tmp = min(tmp, solve(k-c[i]) + 1);
    }
    return dp1[k] = tmp;
}

int main(){
    fill(dp1, dp1+K, INF);
    int k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i){
        scanf("%d", &c[i]);
    }
    printf("%d\n", solve(k));

    fill(dp2, dp2+K, INF);
    dp2[0] = 0;
    for(int i=1; i<=k; ++i){
        for(int j=0; j<n; ++j){
            if(c[j] > i) continue;
            dp2[i] = min(dp2[i], dp2[i-c[j]]+1);
        }
    }
    printf("%d", dp2[k]);
    return 0;
}