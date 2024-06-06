// problem statement is in https://www.hackerrank.com/contests/w28/challenges/boat-trip/leaderboard
#include <stdio.h>

int input[] = {5, 2, 2, 1, 2, 1, 4, 3};

int runMain()
{

   int a = input[0];
    int b = input[1];
    int c = input[2];

    int ok = 1;
    for (int i = 0; i < a; i++)
    {
        int x = input[i + 3];
        if (x > b * c)
            ok = 0;
    }
    if (ok)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    return runMain();
}
