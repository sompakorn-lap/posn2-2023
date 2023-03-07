#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    int n, ans=-1e9;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; ++j){
            int sum = 0;
            for(int k=i; k<=j; ++k){
                sum += a[k];
            }
            ans = max(ans, sum);
        }
    }
    printf("%d", ans);
    return 0;
}