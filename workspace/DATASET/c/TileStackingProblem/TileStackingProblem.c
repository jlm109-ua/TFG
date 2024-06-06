#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++(i))

typedef long long ll;
const int INF = 1e9;

const int N = 1e4;
const int M = 1e3;
const int K = 5e3;

const int MOD = 1e9+7;

int **dp;
int **dp_sum;

void runMain(){
    int n = 3;
    int m = 3;
    int k = 2;
    assert(n >= 1 && n <= N);
    assert(m >= 1 && m <= M);
    assert(k >= 1 && k <= K);

    dp = (int**)malloc((N + 1) * sizeof(int*));
    dp_sum = (int**)malloc((N + 1) * sizeof(int*));
    for(int i = 0; i < N + 1; i++) {
        dp[i] = (int*)malloc((M + 1) * sizeof(int));
        dp_sum[i] = (int*)malloc((M + 1) * sizeof(int));
    }

    REP(j, 0, m) {
        dp[0][j] = 1;
        dp_sum[0][j] = 1;
    }
    REP(i, 1, n) {
        dp[i][0] = 0;
        dp_sum[i][0] = 1;
    }
    REP(j, 1, m) {
        REP(i, 1, n) {
            dp[i][j] = dp_sum[i][j-1];
            if (i > k) {
                dp[i][j] -= dp_sum[i-k-1][j-1];
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
        REP(i, 1, n) {
            dp_sum[i][j] = dp_sum[i-1][j] + dp[i][j];
            dp_sum[i][j] %= MOD;
        }
    }

    for(int i = 0; i < N + 1; i++) {
        free(dp[i]);
        free(dp_sum[i]);
    }
    free(dp);
    free(dp_sum);

}

int main() {
    runMain();
    return 0;
}
