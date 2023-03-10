#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int A[N];

int main(){
    int n, q;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i){
        scanf("%d", &A[i]);
        A[i] += A[i-1];
    }
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        a += 1;
        b += 1;
        printf("%d\n", A[b]-A[a-1]);
    }
    return 0;
}