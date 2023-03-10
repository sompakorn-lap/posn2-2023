#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 505;
const int K = 1e5+5;
int dp[N][K];
pii wv[N];
bool vis[N][K];

int solve(int i, int k){
    if(i == 0) return 0;
    if(k == 0) return 0;

    if(vis[i][k]) return dp[i][k];
    vis[i][k] = true;

    int tmp = 0;
    for(int j=0; j<i; ++j){
        int v, w;
        tie(w, v) = wv[j];
        if(w > k) tmp = solve(i-1, k);
        else tmp = max(solve(i-1, k), solve(i-1, k-w)+v);
    }
    return dp[i][k] = tmp;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i){
        scanf("%d %d", &wv[i].first, &wv[i].second);
    }
    printf("%d", solve(n+1, k));
    return 0;
}