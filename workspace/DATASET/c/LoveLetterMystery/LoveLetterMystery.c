#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void runMain(){
    int T = 4;
    char strings[][1000] = {"abc", "abcba", "abcd", "cba"};

    int az = 89;
    while (T > 0)
    {
        char str[1000];
        strcpy(str, strings[4 - T]);

        int nLen = strlen(str) - 1;
        int count = 0;

        az = 89;
        for (int i = 0; i < nLen / 2; i++)
        {
            int nLeft = (int)str[i];
            int nRight = (int)str[nLen - 1 - i];
            count += abs(nRight - nLeft);
        }

        --T;
    }
}

int main()
{
   runMain();
   return 0;
}
