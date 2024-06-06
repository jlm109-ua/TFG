#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void runMain(){
    int T = 2; // Número de casos de prueba
    char input[][5] = {"acxz", "bcxz"}; // Valores de entrada

    for (int i = 0; i < T; i++)
    {
        char s[10000];
        strcpy(s, input[i]);

        bool bFlag = true;
        size_t n = strlen(s);
        size_t left = 0;
        size_t right = n - 1;

        while ((left < n - 1) && (right > 0))
        {
            if (abs((s[left + 1] - '0') - (s[left] - '0')) !=
                abs((s[right - 1] - '0') - (s[right] - '0')))
            {
                bFlag = false;
                break;
            }
            left++;
            right--;
        }
    }
}

int main()
{
    runMain();
    return 0;
}
