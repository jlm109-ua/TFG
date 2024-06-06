// problem statemnt is in https://www.hackerrank.com/challenges/extra-long-factorials/problem
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int mult(int size, int res[], int x)
{
    int carry = 0, prod;
    for (int j = 0; j < size; j++)
    {
        prod = res[j] * x + carry;
        res[j] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    return size;
}

void fact(int n)
{
    int i, size;
    int res[200];
    res[0] = 1;
    size = 1;
    for (i = 2; i <= n; i++)
    {
        size = mult(size, res, i);
    }
}

void runMain()
{
    int n = 25;
    fact(n);
}

int main()
{
    runMain();
    return 0;
}
