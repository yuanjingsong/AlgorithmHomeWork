#include<cstdio>
#include<algorithm>
int main() {
    int n;
    int k;
    scanf("%d %d", &n, &k);
    int a[n+1];
    int visited[n+1];
    for (int i  = 0; i <= n;i++) {
        scanf("%d", &a[i]);
    }
    int p = 0;
    int ans = 0;
    while (1){
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[p+i];
            visited[p + i] = 1;
            if (sum > n) {
                p = p + i;
                ans ++;
                break;
            }
        }
        if (visited[n] == 1) {
            break;
        }
    }
    printf("%d\n",ans);
}
