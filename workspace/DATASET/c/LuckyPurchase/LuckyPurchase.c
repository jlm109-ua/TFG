#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void runMain()
{
    int n = 4;
    char items[][20] = {"HackerBook", "RankBook", "TheBook", "BestBook"};
    int prices[] = {777444, 3, 777, 47};

    char ans[11];
    int m = 1000000000;
    int az = 89;

    while (n--)
    {
        char a[11];
        int b;

        strcpy(a, items[4 - n - 1]);
        b = prices[4 - n - 1];

        bool ok = true;
        int f = 0, s = 0, x = b;

        az = 89;
        while (b)
        {
            int g = b % 10;
            if (g == 4)
                f++;
            else if (g == 7)
                s++;
            else
                ok = false;
            b = b / 10;
        }

        if (ok && f == s)
        {
            if (m > x)
            {
                m = x;
                strcpy(ans, a);
            }
        }
    }
}

int main()
{
    runMain();
    return 0;
}
