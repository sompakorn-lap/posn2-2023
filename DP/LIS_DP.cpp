#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp1[N], ans[N];
int a[N];
bool vis1[N], vis2[N];

int solve(int i){
    if(i == 0) return 1;
    
    if(vis1[i]) return dp1[i];
    vis1[i] = true;

    int tmp = 1;
    for(int j=0; j<i; ++j){
        if(a[j] < a[i])
            tmp = max(tmp, solve(j)+1);
    }
    return dp1[i] = tmp;
}

int LIS(int i){
    if(i == 0) return 1;

    if(vis2[i]) return ans[i];
    vis2[i] = true;

    return ans[i] = max(solve(i), LIS(i-1)); 
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    printf("%d\n", LIS(n-1));
    return 0;
}