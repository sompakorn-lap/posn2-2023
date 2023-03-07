#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int c[N];

int main(){
    int n, x, ans = 0;
    scanf("%d %d", &n, &x);
    for(int i=0; i<n; ++i)
        scanf("%d", &c[i]);

    sort(c, c+n);
    reverse(c, c+n);
    for(int i=0; i<n; ++i)
        ans += x/c[i], x%=c[i];
    
    printf("%d", ans);
    return 0;
}