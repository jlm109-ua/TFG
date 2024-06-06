#include <stdio.h>
#include <stdint.h>
#include <math.h>

void runMain(uint64_t T, uint64_t *cases) {
    for (uint64_t i = 0; i < T; i++) {
        uint64_t N = cases[i];
        uint64_t nr = floor((N - 1) / 3);
        uint64_t sum = 3 * (nr * (nr + 1) / 2);
        nr = floor((N - 1) / 5);
        sum += 5 * (nr * (nr + 1) / 2);
        nr = floor((N - 1) / 15);
        sum -= 15 * (nr * (nr + 1) / 2);
        printf("%lu\n", sum);
    }
}

int main() {
    uint64_t T = 2; // Número de casos de prueba
    uint64_t cases[2] = {3, 10}; // Valores de N para cada caso de prueba
    runMain(T, cases);
    return 0;
}
