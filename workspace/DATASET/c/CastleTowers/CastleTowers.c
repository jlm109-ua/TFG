// problem statement is in https://www.hackerrank.com/contests/optimization-oct17/challenges/castle-towers/problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int castleTowers(int n, int ar[])
{
    int maxi = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i] > maxi)
        {
            maxi = ar[i];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == maxi)
        {
            cnt++;
        }
    }
    return cnt;
}

int runMain()
{
    int n = 4;
    int ar[] = {3, 2, 1, 3};

    int result = castleTowers(n, ar);
    return result;
}

int main()
{
    return runMain();
}
