#include <cstdio>
#include <cstring>
#define size 6
int a[size + 1][size + 1];
int b[size];
void showMartix(int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int check(int i, int j, int num) {
    for (int m =0; m < size; m++) {
        if (a[i][m] == b[i]) {
            return 0;        
        }
    }
    for (int k = 0; i < size; i++) {
        if (a[k][j] == num && k != i) {
            return 0;
        }
    }
    return 1;
}
void copy(int begin, int end, int n)
{
}

void copyOdd(int begin, int end, int n)
{
    int p, q;
    p = q = 0;
    int mid = begin + n / 2;
    for (int i = 0; i < n; i++)
        b[i] = 0;
    for (int j = 1; j <= mid; j++) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 0) {
                if (!q) {
                    q = i;
                } else {
                    p = i;
                }
            }
        }
        a[q][j] = a[p][0];
        a[p][j] = a[q][0];
        b[q] = p;
        b[p] = q;
        q = p = 0;
    }
    for (int j = 0; j < mid; j++) {
        int cout = 0;
        int i = (mid + 1) % 3;
        while(cout < mid - 1) {
            if(check(j,i+3,a[i+3][0])) {
                a[j][i+3] = a[i+3][0];
                a[a[i+3][0] - 1][i+3] = a[j][0];
                cout ++;
            }else {
                i %= 3;
            }
        }
    }
    showMartix(n);
}

void tourna(int begin, int end, int n)
{
    if (n == 2) {
        a[begin][1] = a[end][0];
        a[end][1] = a[begin][0];
        return;
    } else if (n == 3) {
        a[begin][1] = a[begin + 1][0];
        a[begin][2] = a[end][0];
        a[begin][3] = 0;
        a[begin + 1][1] = a[begin][0];
        a[begin + 1][2] = 0;
        a[begin + 1][3] = a[end][0];
        a[end][1] = 0;
        a[end][2] = a[begin][0];
        a[end][3] = a[begin + 1][0];
        return;
    }

    if (n & 1) {
        tourna(begin, end + 1, n + 1);
        return;
    }
    int mid = begin + n / 2;
    tourna(begin, mid - 1, n / 2);
    tourna(mid, end, n / 2);
    if ((n / 2) & 1) {
        copyOdd(begin, end, n);
    } else {
        copy(begin, end, n);
    }
}
int main()
{
    memset(a, sizeof(a), 0);
    for (int i = 0; i < 6; i++) {
        a[i][0] = i + 1;
    }
    tourna(0, 5, 6);
}
