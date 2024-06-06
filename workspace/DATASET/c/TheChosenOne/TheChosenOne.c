// Date:17-01-17

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#define ll long long
#define CPS CLOCKS_PER_SEC
#define For(i, n) for (i = 0; i < n; i++)
#define rep(i, a, b) for (i = (a); i <= (b); i++)
#define mset(a, value) memset(a, value, sizeof(a))
#define s(a) scanf("%d", &a);
#define ls(a) scanf("%ld", &a)
#define ld double
#define lls(a) scanf("%lld", &a)
#define reg(i) register int i
#define INF 0xfffffffffffffLL
#define MAX 100001
int min(int a, int b) { return (a < b ? a : b); }
int max(int a, int b) { return (a > b ? a : b); }
/*ll L[MAX] ,R[MAX];
void merge(int a[],int p ,int q ,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int i,j,k;
    for(i=0;i<n1;i++)	L[i] = a[p+i];
    for(j=0;j<n2;j++)	R[j] = a[q+j+1];
    L[n1] = INF;
    R[n2] = INF;
    i=0 ,j=0;
    for(k=p;k<=r;k++){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
    }
}
void merge_sort(int a[],int p,int r){
    int q;
    if(p<r){
        q = (p+r)/2;
        merge_sort(a ,p ,q);
        merge_sort(a ,q+1 ,r);
        merge(a ,p ,q ,r);
    }
}*/
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void runMain()
{
    int n, i;
    freopen("/workspace/DATASET/kernel/c/input_files/TheChosenOne", "r", stdin);
    scanf("%d", &n);
    ll a[n];
    For(i, n) lls(a[i]);
    ll g = a[0], prev = g;
    bool f = 0;
    if (n == 1)
    {
        printf("%lld", a[0] + 1);
    }
    else
    {
        rep(i, 1, n - 1)
        {
            g = gcd(g, a[i]);
            if (g == 1)
            {
                g = prev;
                f = 1;
            }
            prev = g;
        }
        if (f)
            printf("%lld", g);
        else
        {
            For(i, n) a[i] /= g;
            if (a[0] == 1)
            {
                g = a[1];
                rep(i, 2, n - 1) g = gcd(g, a[i]);
            }
            else
            {
                g = a[0];
                prev = g;
                rep(i, 2, n - 1)
                {
                    g = gcd(g, a[i]);
                    if (g == 1)
                        g = prev;
                    prev = g;
                }
            }
            printf("%lld", g);
        }
    }
    // your code goes here
}

int main()
{
    runMain();
    return 0;
}