#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> ans;
    for(int i=1; i*i<=n; ++i){
        if(n%i == 0){
            printf("%d ", i);
            ans.push_back(n/i);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans){
        if(i*i == n) continue;
        printf("%d ", i);
    }
    return 0;
}