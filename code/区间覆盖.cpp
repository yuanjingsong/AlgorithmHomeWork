#include<cstdio>
#include<algorithm>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    std::sort(a, a+n);
    int ans = 1;
    int begin = a[0];
    for (int i = 1; i <n; i++) {
        if (a[i] - begin > k) {
            ans ++;
            begin = a[i];
        }
    }
    printf("%d\n", ans);
}
