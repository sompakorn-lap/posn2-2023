#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];
int tmp[N];
int ans = 0;

void mmerge(int l, int m, int r){
    int p=l, q=m+1;
    for(int i=l; i<=r; ++i){
        if(p > m) tmp[i] = a[q++];
        else if(q > r) tmp[i] = a[p++];
        else {
            if(a[q] < a[p]) ans += (m-p+1);
            tmp[i] = (a[p] < a[q]) ? a[p++] : a[q++];
        }
    }
    for(int i=l; i<=r; ++i)
        a[i] = tmp[i];
    return ;
}

void msort(int l, int r){
    if(l == r) return ;
    
    int m = (l+r)/2;
    msort(l, m);
    msort(m+1, r);
    mmerge(l, m, r);
    return ;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
    }
    msort(0, n-1);
    for(int i=0; i<n; ++i){
        printf("%d ", a[i]);
    }
    printf("\n%d", ans);
    return 0;
}