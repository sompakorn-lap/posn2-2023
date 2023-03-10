#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 5e5+5;
int h[N], ans[10'005];
vector<pii> Q;

int main(){
    int n, q, a;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; ++i){
        scanf("%d", &h[i]);
        if(i > 0) h[i] = max(h[i], h[i-1]);
    }
    for(int i=0; i<q; ++i){
        scanf("%d", &a);
        Q.push_back({ a, i });
    }
    h[n] = INT_MAX;
    int tmp = 0, idx = 0;
    sort(Q.begin(), Q.end());
    for(int i=0; i<q;){
        if(Q[i].first < h[idx])
            ans[Q[i].second] = idx, ++i;
        else 
            ++idx;
    }
    printf("---\n");
    for(int i=0; i<q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}