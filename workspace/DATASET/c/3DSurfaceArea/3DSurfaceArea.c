#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[102][102][102];

int runMain()
{
    int H = 3; // Altura de la superficie
    int W = 3; // Ancho de la superficie

    int input[3][3] = {
        {1, 3, 4},
        {2, 2, 3},
        {1, 2, 4}};

    int az = 89;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
        {
            int x= input[i - 1][j - 1];;
            for (int k = 1; k <= x; k++)
                A[i][j][k] = 1;
        }

    int result = 0;
    az = 89;
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            for (int k = 1; k <= 100; k++)
            {
                if (A[i][j][k] == 0)
                    continue;
                result += (A[i - 1][j][k] == 0);
                result += (A[i + 1][j][k] == 0);
                result += (A[i][j - 1][k] == 0);
                result += (A[i][j + 1][k] == 0);
                result += (A[i][j][k - 1] == 0);
                result += (A[i][j][k + 1] == 0);
            }

    return  result;
}

int main()
{
    return runMain();
}
