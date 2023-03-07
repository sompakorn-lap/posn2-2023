#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int s[N], b[N];

int main(){
    int n, ans=2e9+5;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d %d", &s[i], &b[i]);
    
    for(int i=1; i<(1<<n); ++i){
        int sumS=1, sumB=0;
        for(int j=0, k=i; j<n && k>0; ++j, k/=2){
            if(k%2){
                sumS *= s[j];
                sumB += b[j];
            }
        }
        ans = min(ans, abs(sumS-sumB));
    }
    printf("%d", ans);
    return 0;
}