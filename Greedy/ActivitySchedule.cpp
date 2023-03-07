#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 1e5+5;
pii a[N];

int main(){
    int n, s, e;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d %d", &s, &e);
        a[i] = {e, s};
    }
    sort(a, a+n);

    int ans = 0, last = 0;
    for(int i=0; i<n; ++i){
        tie(e, s) = a[i];
        if(last <= s){
            ++ans;
            last = e;
        }
    }
    printf("%d", ans);
    return 0;
}