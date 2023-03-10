#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int N = 5e5+5;
int a[N];
priority_queue<pii, vector<pii>, greater<pii> > pq;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; ++i){
        scanf("%d", &a[i]);
    }
    pq.push({a[0], 0});
    for(int i=1; i<n; ++i){
        while(!pq.empty() && i-pq.top().second > k)
            pq.pop();
        pq.push({ pq.top().first+a[i], i });
    }
    while(!pq.empty() && pq.top().second < n-1)
        pq.pop();
    printf("%d", pq.top().first);
    return 0;
}