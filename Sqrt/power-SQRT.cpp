#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll pw(ll a, ll b, ll m){
    ll tmp = 1;
    ll k = sqrt(b);
    for(int i=0; i<k; ++i)
        tmp = (tmp * a)%m;
    
    ll ans = 1;
    for(int i=0; i<k; ++i)
        ans = (ans * tmp)%m;
    
    for(int i=k*k; i<b; ++i)
        ans = (ans * a)%m;
    return ans;
}

int main(){
    int q;
    ll a, b, m;
    scanf("%d", &q);
    while(q--){
        scanf("%lld %lld %lld", &a, &b, &m);
        printf("%lld\n", pw(a, b, m));
    }
    return 0;
}