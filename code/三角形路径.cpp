#include<cstdio>
#include<cstring>
#include<algorithm>
#define Max 100
using namespace std;
int Triangle[Max][Max];
int dp[Max][Max];
int ans;
int n;

void dfs(int i, int j) {
    if (i == n-1) {
        dp[i][j] = Triangle[i][j];
        return;
    }
    if (dp[i][j]) return;
    dfs(i + 1, j);
    dfs(i + 1, j + 1);
    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + Triangle[i][j];
}

void calc() {
    //from bottom to top
    for (int i = 0; i < n; i++) {
        dp[n-1][i] = Triangle[n-1][i];
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + Triangle[i][j] ;
        }
    }
}

void calc2() { // dp[i][j] is the cost of (0,0) to (i, j)
    //from top to bottom
    dp[0][0] = Triangle[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + Triangle[i][0];
        dp[i][i] = dp[i-1][i-1] + Triangle[i][i];
        for (int j = 1; j < i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + Triangle[i][0];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ans < dp[n-1][i]) {
            ans = dp[n-1][i];
        }
    }
    printf("%d", ans);
}

int main() {
    memset(Triangle, 0, sizeof(Triangle));
    memset(dp, 0, sizeof(dp));
    ans = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d",&Triangle[i][j]);
        }
    }
    //dfs(0,0);
    //calc2();
    //printf("%d", dp[0][0]);
}
