#include<cstdio>
#include<algorithm>
#define Max 100;
void calcP(double a[], double p[], int n) {
    int sum = 0;
    for (int i = 0; i < n ;i++) {
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        p[i] = a[i] / sum;
    }
}




int main() {
    int n;
    scanf("%d",&n);
    double a[n]; 
    double p[n];
    double solve[n];
    for (int i = 0; i < n; i++)
        scanf("%lf",&a[i]);
    calcP(a, p, n);
    std::sort(p, p+n);
    int j = (n -1)/2;
    int flag = 1;
    for (int i = n-1; i >= 0; i--) {
        if (flag) {
            solve[j + (n - i)/2] = p[i];
            flag = 0;
        }else {
            solve[j - (n- i)/2] = p[i];
            flag = 1;
        }
    }
    double ans = 0;
    for(int i = 0; i < n; i++) {
        for (int j = i + 1; j <n ;j++) {
            ans += (j - i) * solve[i]*solve[j];
        }
    }
    printf("%lf\n", ans);
}
