#include <bits/stdc++.h>
using namespace std;
#define iii tuple<int, int, int>
#define arr array

const int N = 1e5+5;
iii a[N];
int dp[N];
int n;

int bs(int l, int r, int s){
    int m;
    while(l < r){
        m = (l+r)/2;
        int e = get<0>(a[m]);
        if(e > s) r = m;
        else l = m+1;
    }
    return l-1;
}

int main(){
    int s, e, w;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d %d %d", &s, &e, &w);
        a[i] = {e, s, w};
    }
    sort(a, a+n);
    dp[0] = get<2>(a[0]);
    for(int i=1; i<n; ++i){
        tie(e, s, w) = a[i];
        int p = bs(0, i, s);
        if(p >= 0 && p < i)
            dp[i] = max(dp[p]+w, dp[i-1]);
        else 
            dp[i] = max(w, dp[i-1]);
    }
    printf("%d", dp[n-1]);
    return 0;
}