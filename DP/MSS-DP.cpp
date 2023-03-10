#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int x[N];
int dp1[N], pref[N];
bool vis1[N], vis2[N];

int maxPrefix(int i){
    if(i == 0) return x[0];

    if(vis2[i]) return pref[i];
    vis2[i] = true;

    return pref[i] = max(maxPrefix(i-1)+x[i], x[i]);
}

int solve(int i){
    if(i == 0) return x[0];
    
    if(vis1[i]) return dp1[i];
    vis1[i] = true;

    return dp1[i] = max(maxPrefix(i-1)+x[i], solve(i-1));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &x[i]);
    printf("%d\n", solve(n-1));

    int ans = x[0], prefix = x[0];
    for(int i=1; i<n; ++i){
        prefix = max(prefix+x[i], x[i]);
        ans = max(ans, prefix);
    }
    printf("%d", ans);
    return 0;
}