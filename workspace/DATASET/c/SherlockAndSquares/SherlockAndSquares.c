#include <stdio.h>
#include <math.h>

void runMain() {
    int T = 2;
    long long tests[][3] = {{3, 9}, {17, 24}};

    for (int t = 0; t < T; t++) {
        long long A = tests[t][0];
        long long B = tests[t][1];
        long count = 0;

        long long s = sqrt(A);
        if (s * s != A)
            s = s + 1;

        for (long long i = s; i * i <= B; i++) {
            count++;
        }
    }
}

int main() {
    runMain();
    return 0;
}
