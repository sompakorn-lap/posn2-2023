#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
    int n, a;
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &a);
        int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
        if(idx == v.size())
            v.push_back(a);
        else 
            v[idx] = a;
    }
    printf("%d", v.size());
    return 0;
}