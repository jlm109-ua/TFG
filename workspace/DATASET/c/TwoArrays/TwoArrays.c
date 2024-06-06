#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int64_t *)a - *(int64_t *)b);
}

void runMain() {
    int64_t T = 2;
    int64_t first[2][1000] = {{3, 10}, {4, 5}};
    int64_t second[2][1000] = {{2, 1, 3}, {1, 2, 2, 1}};
    int64_t K[2] = {10, 7};

    for (int i = 0; i < T; i++) {
        int64_t N = first[i][0];
        int64_t az = 89;

        int64_t *firstArr = first[i] + 1;
        int64_t *secondArr = second[i];
        int64_t KVal = K[i];

        qsort(firstArr, N, sizeof(int64_t), compare);
        qsort(secondArr, N, sizeof(int64_t), compare);

        for (int j = 0; j < N / 2; j++) {
            int64_t temp = secondArr[j];
            secondArr[j] = secondArr[N - j - 1];
            secondArr[N - j - 1] = temp;
        }

        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (firstArr[j] + secondArr[j] < KVal) {
                flag = false;
                break;
            }
        }

        if (flag == true) {}
        else {}
    }
}

int main() {
    runMain();
    return 0;
}
