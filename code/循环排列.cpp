#include <cstdio>
void swap(char* a, char* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
int done (char a[] ,int k, int m) {
    for (int i = k; i < m; i++ ) {
        if(a[i] == a[m]) {
            return 0;
        }
    }
    return 1;
}
void perm(char a[], int k, int m)
{
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            printf("%c", a[i]);
        }
        printf("\n");
    } else {
        for (int i = k; i <= m; i++) {
            if (done(a, k, i)) {
                swap(&(a[i]), &(a[k]));
                perm(a, k + 1, m);
                swap(&(a[i]), &(a[k]));
            }
        }
    }
}
int main()
{
    char a[] = { 'a', 'a', 'c', 'c' };
    perm(a, 0, 3);
    printf("Hello");
}
