#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    while(q--){
        int x, y;
        scanf("%d %d", &x, &y);
        a[x]++;
        a[y+1]--;
    }
    for(int i=1; i<=n; ++i)
        a[i]+=a[i-1], printf("%d ", a[i]);
    return 0;
}