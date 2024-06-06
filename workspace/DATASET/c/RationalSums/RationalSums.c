#include <stdio.h>
#include <stdlib.h>

#define N 5005

typedef long long ll;

ll MOD = 1000000007;

ll a[N], b[N], c[N];
ll harm[N];

ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll mod_inv(ll a, ll m) {
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

ll harm_series(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
        res = (res + mod_inv(i, MOD)) % MOD;
    }
    return res;
}

void runMain() {
    int n;
    int queries[][2] = {{0, 1, 2}, {1, 3}};
    int num_queries = sizeof(queries) / sizeof(queries[0]);
    for (int q_idx = 0; q_idx < num_queries; q_idx++) {
        n = sizeof(queries[q_idx]) / sizeof(queries[q_idx][0]);
        for (int i = 0; i < n; i++)
            a[i] = queries[q_idx][i];
        for (int i = 0; i < n - 1; i++)
            b[i] = queries[q_idx + 1][i];
        for (int i = 0; i < n; i++) {
            ll num = 0;
            for (int j = n - 2; j >= 0; j--) {
                num *= -a[i];
                num += b[j];
                num = (num % MOD + MOD) % MOD;
            }
            ll denom = 1;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                denom *= a[j] - a[i];
                denom = (denom % MOD + MOD) % MOD;
            }
            c[i] = (num * mod_inv(denom, MOD)) % MOD;
        }
        ll maxa = 0;
        for (int i = 0; i < n; i++)
            maxa = (a[i] > maxa) ? a[i] : maxa;
        harm[0] = 0;
        for (int i = 1; i <= maxa; i++) {
            harm[i] = harm[i - 1] + mod_inv(i, MOD);
            harm[i] %= MOD;
        }
        ll ret = 0;
        for (int i = 0; i < n; i++) {
            ret += c[i] * harm[maxa] - c[i] * harm[a[i]];
            ret = (ret % MOD + MOD) % MOD;
        }
    }
}

int main() {
    runMain();
    return 0;
}
