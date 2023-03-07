#include <bits/stdc++.h>
using namespace std;

int bucket[2005];

int main(){
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &x);
        bucket[x+1000]++;
    }
    for(int i=-1000; i<=1000; ++i){
        for(int j=0; j<bucket[i+1000]; ++j){
            printf("%d ", i);
        }
    }
    return 0;
}