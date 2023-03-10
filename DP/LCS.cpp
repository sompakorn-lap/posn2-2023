#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char A[N], B[N];
int dp1[N][N], dp2[N][N];
bool vis1[N][N];

int solve(int i, int j){
    if(i == 0 || j == 0) return 0;

    if(vis1[i][j]) return dp1[i][j];
    vis1[i][j] = true;

    if(A[i] == B[j])
        return dp1[i][j] = solve(i-1, j-1) + 1;
    else 
        return dp1[i][j] = max(solve(i-1, j), solve(i, j-1));
}

int main(){
    scanf("%s %s", A+1, B+1);
    int a=strlen(A+1), b=strlen(B+1);
    printf("%d\n", solve(a, b));

    for(int i=1; i<=a; ++i){
        for(int j=1; j<=b; ++j){
            if(A[i] == B[j])
                dp2[i][j] = dp2[i-1][j-1]+1;
            else
                dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
        }
    }
    printf("%d", dp2[a][b]);
    return 0;
}