#include<cstdio>
#include<cstring>
#define Max 100
int a[100];
long comp(int n) {
    long ans = 1;
    if (a[n] > 0) return a[n];
    for (int i = 1; i <= n/2; i ++) 
        ans += comp(i);
    a[n] = ans;
    return ans;
}

int main() {
    memset(a, sizeof(a), 0);
    a[1] = 1;
    int n;
    scanf("%d",&n);
    printf("%ld",comp(n));
}
