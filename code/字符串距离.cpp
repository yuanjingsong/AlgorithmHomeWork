#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstring>
#define Max 100
using namespace std;

int dp[Max][Max];
char A[Max];
char B[Max];
int k;

int min (int a, int b, int c) {
    return a < b ? std::min(a, c) : std:: min(b, c);
}

int distance(char a, char b) {
    return abs(a - b);
}

void solve(int m, int n) {
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i-1][0] + k  ;
    }

    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dp[i-1][0] + k;
    }

    for (int i = 1; i <= m; i ++)  {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i-1][j-1] + distance(A[i-1], B[j-1]), dp[i-1][j] + k, dp[i][j-1] + k) ;
        }
    }
    printf ("%d", dp[m][n]);
}

int main() {
    memset(dp, 0, sizeof(dp));
    cin>>A;
    cin>>B;
    k = 2;
    solve(3, 4);
}
