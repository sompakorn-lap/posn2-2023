#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
    }

    int lb=0, rb=n-1, mb, ans = -1;
    while(lb <= rb){
        mb = (lb+rb)/2;

        if(a[mb] >= k){
            rb = mb-1;
            if(a[mb] == k)
                ans = mb;
        }
        else {
            lb = mb + 1;
        }
    }
    printf("%d", ans);
    return 0;
}