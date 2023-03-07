#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int MSS(int l, int r){
    if(l == r) return a[l];

    int m = (l+r)/2;
    int L = MSS(l, m);
    int R = MSS(m+1, r);

    int prefix = 0, maxPrefix = a[m];
    for(int i=m; i>=l; --i){
        prefix += a[i];
        maxPrefix = max(maxPrefix, prefix);
    }
    int suffix = 0, maxSuffix = a[m+1];
    for(int i=m+1; i<=r; ++i){
        suffix += a[i];
        maxSuffix = max(maxSuffix, suffix);
    }
    return max({L, R, maxPrefix+maxSuffix});
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    
    printf("%d", MSS(0, n-1));
    return 0;
}