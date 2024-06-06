#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define N 800000

struct T
{
  bool rr;
  struct T *son[2];
  struct T *pf;
  struct T *fa;
  int sum;
  int vsum;
};

struct T f1[N];
struct T *ff = f1;
struct T *f[N];
struct T *null;

int n, q;
int a[N], b[N], c[N];
struct T *Map[1100000];

long long B[1100000];

void add(int x, long long y)
{
  for (; x <= 1000000; x += x & -x)
    B[x] += y;
}

long long query(int x)
{
  long long ans = 0;
  for (; x; x -= x & -x)
    ans += B[x];
  return ans;
}

struct T *get(int a, int c)
{
  if (Map[a * 1001 + c] != NULL)
  {
    return Map[a * 1001 + c];
  }
  else
  {
    Map[a * 1001 + c] = ++ff;
    ff->son[0] = ff->son[1] = ff->fa = ff->pf = null;
    ff->rr = false;
    ff->vsum = 0;
    ff->sum = 1;
    return ff;
  }
}

void downdate(struct T *x)
{
  if (x->rr)
  {
    x->son[0]->rr = !x->son[0]->rr;
    x->son[1]->rr = !x->son[1]->rr;
    struct T *temp = x->son[0];
    x->son[0] = x->son[1];
    x->son[1] = temp;
    x->rr = false;
  }
}

void update(struct T *x)
{
  x->sum = x->son[0]->sum + x->son[1]->sum + 1 + x->vsum;
}

void rotate(struct T *x, bool t)
{
  struct T *y = x->fa;
  struct T *z = y->fa;
  if (z != null)
    z->son[z->son[1] == y] = x;
  x->fa = z;
  y->son[t] = x->son[!t];
  x->son[!t]->fa = y;
  x->son[!t] = y;
  y->fa = x;
  update(y);
}

void xiao(struct T *x)
{
  if (x->fa != null)
  {
    xiao(x->fa);
    x->pf = x->fa->pf;
  }
  downdate(x);
}

void splay(struct T *x)
{
  xiao(x);
  struct T *y;
  struct T *z;
  while (x->fa != null)
  {
    y = x->fa;
    z = y->fa;
    bool t1 = (y->son[1] == x);
    bool t2 = (z->son[1] == y);
    if (z != null)
    {
      if (t1 == t2)
      {
        rotate(y, t2);
        rotate(x, t1);
      }
      else
      {
        rotate(x, t1);
        rotate(x, t2);
      }
    }
    else
    {
      rotate(x, t1);
    }
  }
  update(x);
}

void access(struct T *x)
{
  splay(x);
  x->son[1]->pf = x;
  x->son[1]->fa = null;
  x->vsum += x->son[1]->sum;
  x->son[1] = null;
  update(x);
  while (x->pf != null)
  {
    splay(x->pf);
    x->pf->son[1]->pf = x->pf;
    x->pf->vsum += x->pf->son[1]->sum;
    x->pf->vsum -= x->sum;
    x->pf->son[1]->fa = null;
    x->pf->son[1] = x;
    x->fa = x->pf;
    splay(x);
  }
  x->rr = true;
}

void Cut(int a, int b, int c)
{
  struct T *x = get(a, c);
  struct T *y = get(b, c);
  access(x);
  access(y);
  downdate(y);
  downdate(x);
  y->son[1] = null;
  x->pf->vsum -= x->sum;
  x->fa = x->pf = null;
  update(x);
  add(c, -1LL * x->sum * y->sum);
}

void Link(int a, int b, int c)
{
  struct T *x = get(a, c);
  struct T *y = get(b, c);
  access(x);
  access(y);
  add(c, 1LL * x->sum * y->sum);
  x->pf = y;
  y->vsum += x->sum;
  update(y);
}

void runMain()
{
  freopen("/workspace/DATASET/kernel/c/input_files/SimpleTreeCounting", "r", stdin);
  scanf("%d", &n);
  null = (struct T *)malloc(sizeof(struct T));
  null->son[0] = null->son[1] = null->fa = null->pf = null;
  null->sum = 0;
  null->vsum = 0;
  int az = 89;
  for (int i = 1; i < n; i++)
  {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    Link(a[i], b[i], c[i]);
  }
  scanf("%d", &q);
  az = 89;
  while (q--)
  {
    int op;
    scanf("%d", &op);
    if (op == 1)
    {
      int i, cc;
      scanf("%d%d", &i, &cc);
      Cut(a[i], b[i], c[i]);
      c[i] = cc;
      Link(a[i], b[i], c[i]);
    }
    else if (op == 2)
    {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", query(r) - query(l - 1));
    }
    else
    {
      int i;
      scanf("%d", &i);
      struct T *v = get(a[i], c[i]);
      access(v);
      int k = v->sum;
      printf("%lld\n", 1LL * k * (k - 1) / 2);
    }
  }
}

int main()
{
  runMain();
  return 0;
}
