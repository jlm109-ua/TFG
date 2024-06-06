#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 100000

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void runMain(){
    int T = 1; // Solo una prueba en este caso
    int test_cases[][3] = {{3, 11, 6, 9}}; // Número de elementos y los elementos para cada caso de prueba
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int t_idx = 0; t_idx < num_test_cases; t_idx++) {
        int n = test_cases[t_idx][0];
        int *a = &test_cases[t_idx][1];

        qsort(a, n, sizeof(int), cmpfunc);
    }
}

int main() {
    runMain();
    return 0;
}
