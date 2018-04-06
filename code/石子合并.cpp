#include<cstdio>
#include<cstring>
#define Max 100

int dp[Max][Max];
int cost[Max];
int n;

int calc(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return 0;
    if (r < l) return 0;
    int u = calc(l+1, r-1) + cost[l] + cost[r];
    printf("l is %d , r is %d cost is %d\n",l, r,u);
    for (int i = l; i < r; i++) {
        int t = calc(l, i) + calc(i+1, r);
        if (t < u) {
            u = t;
        }
    }
    int addAll = 0;
    for (int i = l; i <= r; i++) {
        addAll += cost[i];
    }
    dp[l][r] = addAll + u;
    return dp[l][r];
}


void solve() {
    printf("%d",calc(0, n-1));
}

int main() {
    memset(cost, 0, sizeof(cost));
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++ ){
        scanf("%d", &cost[i]);
    }
    solve();
}
