#include <stdio.h>
#include <stdbool.h>

#define MAXN 63

typedef long long ll;
typedef struct { int F, S; } pii;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n, dd;
int vis[MAXN][MAXN];

bool fit(int x, int y) { return 0 <= x && x < n && 0 <= y && y < n && !vis[x][y]; }

void runMain(){
    n = 2;
    char ch = 'e';
    if (ch == 'e')
        dd = 0;
    else if (ch == 's')
        dd = 1;
    else if (ch == 'w')
        dd = 2;
    else
        dd = 3;
    int x = 1;
    int y = 0;
    vis[x][y] = 1;
    for (int t = 2; t <= n*n; t++) {
        int temp = (dd+2)%4;
        if (fit(x+dx[dd], y+dy[dd])) 
            x += dx[dd], y += dy[dd];
        else if (fit(x+dx[(dd+1)%4], y+dy[(dd+1)%4])) 
            x += dx[(dd+1)%4], y += dy[(dd+1)%4];
        else if (fit(x+dx[(dd+3)%4], y+dy[(dd+3)%4])) 
            x += dx[(dd+3)%4], y += dy[(dd+3)%4];
        else 
            x += dx[temp], y += dy[temp];
        vis[x][y] = t;
    }
}

int main() {
    runMain();
    return 0;
}
