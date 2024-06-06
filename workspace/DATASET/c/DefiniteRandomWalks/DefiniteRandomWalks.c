#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MOD 998244353

uint32_t N = 4, M = 5, K = 1;
uint32_t pf[2][60001];
uint32_t next[60001];
uint32_t prob[100000];
uint32_t rrow;

uint32_t pow_mod(uint64_t x, uint64_t k)
{
    uint64_t r;
    while ((k & 1) == 0)
    {
        x = (x * x) % MOD;
        k >>= 1;
    }
    r = x;
    k >>= 1;
    while (k)
    {
        x = (x * x) % MOD;
        if ((k & 1))
            r = (r * x) % MOD;
        k >>= 1;
    }
    return r;
}

void solve(void)
{
    uint32_t n, m, k, pos;
    for (k = 0; k < K; k++, rrow ^= 1)
    {
        for (n = 1; n <= N; n++)
        {
            for (m = 0, pos = n; m < M; m++, pos = next[pos])
            {
                pf[rrow ^ 1][pos] = (pf[rrow ^ 1][pos] + ((uint64_t)pf[rrow][n] * prob[m]) % MOD) % MOD;
            }
        }
        memset(pf[rrow], 0, sizeof(pf[rrow]));
    }
}

void runMain(){
    uint32_t i;
    uint32_t inv;

    inv = pow_mod(N, MOD - 2);

    uint32_t nextInput[] = {2, 3, 2, 4};
    uint32_t probInput[] = {332748118, 332748118, 332748118, 0, 0};

    memcpy(next + 1, nextInput, sizeof(nextInput));
    memcpy(prob, probInput, sizeof(probInput));

    for (i = 1; i <= N; i++)
    {
        pf[0][i] = inv;
    }

    solve();
}

int main(void)
{
    runMain();
    return 0;
}
