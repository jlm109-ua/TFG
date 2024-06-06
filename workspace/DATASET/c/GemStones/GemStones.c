#include <stdio.h>
#include <string.h>

int runMain() {
   int n, i, j, freq[150][27] = {0}, count;
    char str[200];
    n = 3;  // Número de elementos en el archivo

    // Definir los valores de las cadenas
    char strings[3][200] = {
        "abcdde",
        "baccd",
        "eeabg"
    };

    for (i = 0; i < n; i++)
    {
        // Copiar cada cadena a str
        strcpy(str, strings[i]);

        for (j = 0; str[j] != '\0'; j++)
        {
            freq[i][str[j] - 97]++;
        }
    }
    count = 0;
    for (i = 0; i < 26; i++)
    {
        for (j = 0; j < n; j++)
            if (freq[j][i] > 0)
                continue;
            else
                break;
        if (j == n)
            count++;
    }
    
    return count;
}

int main()
{
    return runMain();
}