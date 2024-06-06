#include <stdio.h>
#include <stdlib.h>

int ways(int n, int *a, int k) {
    //printf("ways(%d, %d)\n", n, k); // Depuración
    if (n < 0) {
        //printf("Returning 0 because n < 0\n"); // Depuración
        return 0;
    }
    if (n == 0) {
        //printf("Returning 1 because n == 0\n"); // Depuración
        return 1;
    }
    if (k <= 0 && n >= 1) {
        //printf("Returning 0 because k <= 0 and n >= 1\n"); // Depuración
        return 0;
    }
    return ways(n, a, k - 1) + ways(n - a[k - 1], a, k);
}

void runMain() {
    int m = 2;
    int n = 4;
    int *coin = (int *)malloc(m * sizeof(int)), i;
    for (i = 0; i < m; i++) {
        coin[i] = 1 << i;
    }

    int result = ways(n, coin, m);
    //printf("Number of ways to generate %d with the available coins: %d\n", n, result);

    free(coin);
}

int main() {
    runMain();
    return 0;
}
