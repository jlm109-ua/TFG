#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include <stdlib.h>


const int N = 100005;
const int M = 1000000007;
typedef long long ll;

int n, q;
int *eu, *ev, *par;
int *sub, *h, *en, *ex, *rev, TIME;
ll *dp, *dep, *ew;
int **adj, *adj_size;

void dfs(int u, int p)
{
    rev[TIME] = u;
    en[u] = TIME++;
    sub[u] = 1;
    for (int i = 0; i < adj_size[u]; ++i)
    {
        int e = adj[u][i];
        int v = eu[e] == u ? ev[e] : eu[e];
        if (v != p)
        {
            ll w = ew[e];
            dep[v] = dep[u] + w;
            h[v] = h[u] + 1;
            par[v] = u;
            dfs(v, u);
            sub[u] += sub[v];
            dp[u] += (dp[v] + w * sub[v] % M) % M;
            dp[u] %= M;
        }
    }
    ex[u] = TIME - 1;
}


int query(int U, int V)
{
    int path[N];
    if (h[U] > h[V])
    {
        int temp = U;
        U = V;
        V = temp;
    }
    if (en[U] <= en[V] && ex[V] <= ex[U])
    {
        int size = h[V] - h[U];
        // U is ancestor of V
        for (int i = size, p = V; i >= 0; --i, p = par[p])
            path[i] = p;
        int L = 0;
        while (L <= size &&
               dep[path[L]] - dep[path[0]] + 1 <= dep[path[size]] - dep[path[L]])
        {
            ++L;
        }
        --L;
        ll ans = 0;
        for (int i = 0; i < size; ++i)
        {
            int ui = path[i];
            int uj = path[i + 1];
            ll w = (dep[uj] % M - dep[ui] % M) % M;
            ll dpu = (dp[ui] - dp[uj] - w * sub[uj] % M) % M;
            ll subu = (sub[ui] - sub[uj]) % M;
            if (i <= L)
            {
                ans += sub[V] * dpu % M + dp[V] * subu % M + (1 - dep[U] % M) % M * sub[V] % M * subu % M + sub[V] * subu % M * (dep[ui] % M) % M;
                ans %= M;
            }
            else
            {
                ans += sub[V] * dpu % M + dp[V] * subu % M + dep[V] % M * sub[V] % M * subu % M - sub[V] * subu % M * (dep[ui] % M) % M;
                ans %= M;
            }
        }
        return ans;
    }
    else
    {
        // case 3
        return (dp[V] * sub[U] % M + dp[U] * sub[V] % M + sub[U] * sub[V] % M) % M;
    }
}

void update(int e, ll x)
{
    int u = eu[e], v = ev[e];
    if (h[u] > h[v])
    {
        int temp = u;
        u = v;
        v = temp;
    }
    ew[e] += x;
    // update ancestors
    for (int a = u; a != 0; a = par[a])
        dp[a] = (dp[a] + x * sub[v] % M) % M;
    for (int i = en[v]; i <= ex[v]; ++i)
        dep[rev[i]] += x;
}

void runMain(){
     freopen("/workspace/DATASET/kernel/c/input_files/ImpressiveTree", "r", stdin);
    scanf("%d%d", &n, &q);

    // Asignación de memoria dinámica
    eu = (int *)malloc(N * sizeof(int));
    ev = (int *)malloc(N * sizeof(int));
    par = (int *)malloc(N * sizeof(int));
    sub = (int *)malloc(N * sizeof(int));
    h = (int *)malloc(N * sizeof(int));
    en = (int *)malloc(N * sizeof(int));
    ex = (int *)malloc(N * sizeof(int));
    rev = (int *)malloc(N * sizeof(int));

    dp = (ll *)malloc(N * sizeof(ll));
    dep = (ll *)malloc(N * sizeof(ll));
    ew = (ll *)malloc(N * sizeof(ll));

    adj = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        adj[i] = (int *)malloc(N * sizeof(int));
    }
    adj_size = (int *)malloc(N * sizeof(int));

    while (q--)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int i, x;
            scanf("%d%d", &i, &x);
            update(i, x);
        }
        else if (t == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            int ans = query(u, v);
            if (ans < 0)
                ans += M;
            printf("%d\n", ans);
        }
        else
        {
            assert(false);
        }
    }

    // Liberar memoria dinámica
    free(eu);
    free(ev);
    free(par);
    free(sub);
    free(h);
    free(en);
    free(ex);
    free(rev);

    free(dp);
    free(dep);
    free(ew);

    for (int i = 0; i < N; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adj_size);

}

int main()
{
    runMain();
    return 0;
}
