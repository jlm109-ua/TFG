#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

void runMain() {
    int T = 2;
    long tests[][4] = {{3, 1, 2, 3}, {3, 1, 1, 2}};

    for (int t = 0; t < T; t++) {
        long n = tests[t][0];
        long mapCount[MAX_SIZE + 1];
        memset(mapCount, 0, sizeof(mapCount));

        for (int i = 1; i <= n; i++) {
            long k = tests[t][i];
            long count = ++mapCount[k];
        }

        long long nTotalPairs = 0;

        for (int i = 1; i <= MAX_SIZE; i++) {
            long nCount = mapCount[i];
            if (nCount > 1)
                nTotalPairs += (nCount * (nCount - 1));
        }
    }
}

int main() {
    runMain();
    return 0;
}
