// problem statement is in https://www.hackerrank.com/challenges/angry-children-2/problem
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100005

long long a[N], sum[N];
long long s(int a, int b) { return sum[b] - (a ? sum[a - 1] : 0LL); }

long long llmin(long long a, long long b)
{
    return a < b ? a : b;
}

int compare(const void *_a, const void *_b) {
 
        int *a, *b;
        
        a = (int *) _a;
        b = (int *) _b;
        
        return (*a - *b);
}

long long runMain() {
    int n, k;

    int inputs[] = {7, 3, 10, 100, 300, 200, 1000, 20, 30};
    int inputIndex = 0;
    n = inputs[inputIndex++];
    k = inputs[inputIndex++];
    for (int i = 0; i < n; i++)
    {
        a[i] = inputs[inputIndex++];
    }
    
    qsort(a, n, sizeof(long long), &compare);

    sum[0] = a[0];
    for(int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];

    long long curr = 0;
    for(int i = 0; i < k; i++)
        curr += (long long)(2 * i + 1) * a[i];

    long long res = curr;
    for(int i = 0; i + k - 1 < n; i++)
    {
        res = llmin(res, curr - k * s(i, i + k - 1));
        curr -= a[i] + 2LL * s(i + 1, i + k - 1);
        curr += (long long)(2 * k - 1) * a[i + k];
    }
   return res;
}

int main()
{
    return runMain();
}
