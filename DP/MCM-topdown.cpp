#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 1e9+7;
int dp[N][N];
int R[N], C[N];
bool vis[N][N];

int solve(int l, int r){
    if(l == r) return 0;

    if(vis[l][r]) return dp[l][r];
    vis[l][r] = true;

    int tmp = INF;
    for(int m=l; m<=r-1; ++m){
        tmp = min(tmp, solve(l, m)+solve(m+1, r)+R[l]*C[m]*C[r]);
    }
    return dp[l][r] = tmp;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d %d", &R[i], &C[i]);
    }
    printf("%d", solve(0, n-1));
    return 0;
}