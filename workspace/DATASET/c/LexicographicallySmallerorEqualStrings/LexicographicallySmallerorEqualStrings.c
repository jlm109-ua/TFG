#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define left_son (node<<1)
#define right_son (node<<1|1)

typedef long long ll;
const int Mod = 1e9 + 7;

int n, i, q, *ans, *aib;

struct SS
{
    char sr[100];
    int id, l, r;
} *s;

int ub(int x) { return (x & (-x)); }

void update(int x)
{
    for (; x <= n; x += ub(x))
        aib[x]++;
}

int query(int x, int y)
{
    int ans = 0;
    for (; y; y -= ub(y))
        ans += aib[y];
    for (--x; x; x -= ub(x))
        ans -= aib[x];
    return ans;
}

int ss_compare(const void *a, const void *b)
{
    struct SS *s1 = (struct SS *)a;
    struct SS *s2 = (struct SS *)b;

    int v = strcmp(s1->sr, s2->sr);
    if (!v)
        return s1->l < s2->l;
    return (v < 0);
}

void runMain(){
    int inputs[][4] = {{5, 2}, {1, 2, 2, 3}};
    char strings[][100] = {"aab", "za", "a", "aa", "aaa", "bc", "aaaa"};

    n = 5; // Número de cadenas
    q = 2; // Número de consultas

    ans = (int *)malloc((2 * n + 5) * sizeof(int));
    aib = (int *)malloc((2 * n + 5) * sizeof(int));
    s = (struct SS *)malloc((2 * n + 5) * sizeof(struct SS));

    for (i = 1; i <= n; ++i)
    {
        strcpy(s[i].sr, strings[i - 1]);
        s[i].id = i;
        s[i].l = s[i].r = -1;
    }

    for (i = 1; i <= q; ++i)
    {
        s[n + i].l = inputs[i - 1][0];
        s[n + i].r = inputs[i - 1][1];
        strcpy(s[n + i].sr, strings[inputs[i - 1][2] - 1]);
        s[n + i].id = i;
    }

    qsort(s + 1, n + q, sizeof(struct SS), ss_compare);

    for (i = 1; i <= n + q; ++i)
    {
        struct SS it = s[i];
        if (it.l != -1)
        {
            ans[it.id] = query(it.l, it.r);
            continue;
        }
        update(it.id);
    }

    free(ans);
    free(aib);
    free(s);
}

int main()
{
    runMain();
    return 0;
}
