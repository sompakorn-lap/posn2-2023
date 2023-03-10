#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp1[N], dp2[N];

int solve(int x){
    if(x == 0) return 1;
    if(x == 1) return 1;
    
    if(dp1[x] != 0) return dp1[x];

    return dp1[x] = solve(x-1) + solve(x-2);
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", solve(x));
    
    dp2[0] = 1;
    dp2[1] = 1;
    for(int i=2; i<=x; ++i)
        dp2[i] = dp2[i-1] + dp2[i-2];
    printf("%d", dp2[x]);
    return 0;
}