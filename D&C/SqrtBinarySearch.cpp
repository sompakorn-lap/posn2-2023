#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int a[N];

int main(){
    int x, ans=0;
    scanf("%d", &x);

    int lb=0, rb=x, mb;
    while(lb <= rb){
        mb = (lb+rb)/2;

        if(mb*mb >= x){
            rb = mb-1;
        }
        else {
            ans = mb;
            lb = mb + 1;
        }
    }
    printf("%d", ans);
    return 0;
}