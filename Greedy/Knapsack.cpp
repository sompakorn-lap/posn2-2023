#include <bits/stdc++.h>
using namespace std;
#define pff pair<double, double>

const int N = 1e5+5;
pff a[N];

int main(){
    int n;
    double v, w, W, ans = 0.0;
    scanf("%d %lf", &n, &W);
    for(int i=0; i<n; ++i){
        scanf("%lf %lf", &v, &w);
        a[i] = {v/w, w};
    }
    sort(a, a+n);
    reverse(a, a+n);

    for(int i=0; i<n; ++i){
        tie(v, w) = a[i];
        ans += v * min(w, W);
        W -= min(w, W);
    }
    printf("%.2lf", ans);
    return 0;
}