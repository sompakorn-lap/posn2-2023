#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    
    sort(a, a+n);
    int sum = 0;
    for(int i=0; i<n; ++i)
        sum += abs(a[i]-a[n/2]);
    
    printf("%d", sum);
    return 0;
}