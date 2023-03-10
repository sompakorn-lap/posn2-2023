#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
int a[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);

    int sum = 0, ans=0;
    for(int i=0; i<k; ++i)
        sum += a[i];
    ans = sum;
    for(int i=k; i<n; ++i){
        sum = sum - a[i-k] + a[i];
        ans = max(ans, sum);
    }
    printf("%d", ans);
    return 0;
}