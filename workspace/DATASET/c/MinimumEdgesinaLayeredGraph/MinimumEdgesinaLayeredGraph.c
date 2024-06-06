#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 110
#define INF 0x3f3f3f3f

int n, k, dp[N][N][N];

int min(int a, int b) {
    return a < b ? a : b;
}

int runMain(){
    n = 4;
    k = 5;

    memset(dp, INF, sizeof dp);
    dp[1][1][1] = 0;

    for (int i = 2; i <= k - 1; ++i) {
        for (int s = 1; s <= n; ++s) {
            for (int d = 1; d <= s; ++d) {
                for (int x = 1; x <= s; ++x) {
                    dp[i][s][d] = min(dp[i][s][d], dp[i - 1][s - d][x] + x * d);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= n - 1; ++i) {
        ans = min(ans, dp[k - 1][n - 1][i] + i);
    }

    if (ans == INF) {
        ans = -1;
    }

    return ans;
}

int main() {
    return runMain();
}
