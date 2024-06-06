/* the problem statement is in https://www.hackerrank.com/contests/101hack52/challenges/construct-the-array/problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 510031
#define bs 1000000007

long long n = 4;
long long k = 3;
long long x = 2;
long long dp[N][3];

long long runMain(){
 dp[1][(x == 1)] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int nw = 0; nw <= 1; nw++) {
                long long ways;
                if (j == 1 && nw == 1)
                    ways = 0;
                if (j == 1 && nw == 0)
                    ways = k - 1;
                if (j == 0 && nw == 1)
                    ways = 1;
                if (j == 0 && nw == 0)
                    ways = (k - 2) > 0 ? (k - 2) : 0;
                dp[i][nw] = (dp[i][nw] + dp[i - 1][j] * ways) % bs;
            }
        }
    }

    return dp[n][1];

}

int main() {
    return runMain();
}

