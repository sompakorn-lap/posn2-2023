#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll pw1(ll a, ll b, ll m){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll tmp = pw1(a, b/2, m);
    tmp = (tmp * tmp)%m;
    if(b%2)
        tmp = (tmp * a)%m;
    return tmp;
}

ll pw2(ll a, ll b, ll m){
    ll ans = 1;
    while(b > 0){
        if(b%2)
            ans = (ans * a)%m;
        a = (a%m * a%m)%m
        b /= 2;
    }
    return ans;
}

int main(){
    int q;
    ll a, b, m;
    scanf("%d", &q);
    while(q--){
        scanf("%lld %lld %lld", &a, &b, &m);
        printf("%lld\n", pw2(a, b, m));
    }
    return 0;
}