#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int min(int a, int b)
{
    return a < b ? a : b;
}

int  runMain()
{
    int n = 3; // Tamaño de la matriz a
    int m = 4; // Tamaño de la matriz b
    int x = 1; // Valor de x
    int k = 5; // Valor de k

    int a[] = {2, -3, 1};     // Matriz a
    int b[] = {3, 1, -2, -1}; // Matriz b

    qsort(a, n, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);

    for (int i = 0; i < min(n, m - x); i++)
    {
        for (int j = i + x; j < m; j++)
        {
            k--;
            if (k < 1)
            {
                return a[i] * b[j];
            }
        }
    }
}

int main()
{
    return runMain();
}