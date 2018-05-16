#include <cstdio>
#include <cstdlib>
#include<cstring>
#define Max 100
int n;
int sum;
int color[Max][Max];
int a[Max][Max];
int visited[Max][Max];
int check(int x, int y, int r, int c) {
    if (visited[r][c]) {
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if(a[x][i] == r && y!= i) {
            return 0;
        }
        if(a[i][y] == r && x != i)  {
            return 0;
        }
        if (color[x][i] == c && y != i) {
            return 0;
        }
        if (color[i][y] == c && x != i) {
            return 0;
        }
        
    }
    return 1;
}
void backtrack(int x, int y, int count) {
    if(count >= n*n) {
        sum ++;
    }
    for(int i = 1; i <= n; i++ ) {
        for (int j = 1; j <= n; j++) {
            if (check(x, y, i, j)){ 
                a[x][y] = i;
                color[x][y] = j;
                visited[i][j] = 1;
                if (y + 1 <= n) {
                    backtrack(x, y+1, count+1);
                }else if(x + 1 <= n) {
                    backtrack(x+1, 1, count+1);
                }
                visited[i][j] = 0;
                a[x][y] = 0;
                color[x][y] = 0;
           }
        }
    }
}
int main() {
    scanf("%d",&n);
    memset(a, 0, sizeof(a));
    memset(color, 0, sizeof(color));
    memset(visited, 0, sizeof(visited));
    sum = 0;
    backtrack(1, 1, 1);
    printf("%d\n", sum);
}
