#include <stdio.h>
#include <math.h>

void runMain() {
    int n = 5;
    int A[] = {1, 2, 3, 4, 5};
    int q = 4;
    int queries[][6] = {
        {2, 1, 5, 1, 1, 110},
        {1, 1, 1, 2},
        {2, 2, 5, 1, 1, 110},
        {2, 3, 3, 1, 2, 728}
    };

    for (int a0 = 0; a0 < q; a0++) {
        int flag = queries[a0][0];

        if (flag == 1) {
            int x1 = queries[a0][1], x2 = queries[a0][2], x3 = queries[a0][3];
            for (int i = x1 - 1; i < x2; i++)
                A[i] = x3;
        }

        if (flag == 2) {
            int array1[101] = {0}, array2[101] = {0};
            int x1 = queries[a0][1], x2 = queries[a0][2], x3 = queries[a0][3], x4 = queries[a0][4];
            long long int x5 = queries[a0][5];

            for (int j = x1 - 1; j < x2; j++) {
                int n = A[j];
                while (n % 2 == 0) {
                    array1[2] += 1;
                    n = n / 2;
                }
                for (int i = 3; i <= sqrt(n); i = i + 2) {
                    while (n % i == 0) {
                        array1[i] += 1;
                        n = n / i;
                    }
                }
                if (n > 2)
                    array1[n] += 1;
            }

            for (int j = x3 - 1; j < x4; j++) {
                int n = A[j];
                while (n % 2 == 0) {
                    array2[2] += 1;
                    n = n / 2;
                }
                for (int i = 3; i <= sqrt(n); i = i + 2) {
                    while (n % i == 0) {
                        array2[i] += 1;
                        n = n / i;
                    }
                }
                if (n > 2)
                    array2[n] += 1;
            }

            int flag = 0;
            for (int i = 2; i <= 100; i++) {
                if (array1[i] >= array2[i])
                    array1[i] = array1[i] - array2[i];
                else {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                long long int sum = 1;
                for (int i = 2; i <= 100; i++) {
                    if (array1[i] > 0) {
                        for (int k = 1; k <= array1[i]; k++)
                            sum = (sum * i) % x5;
                    }
                }
            }
        }
    }
}

int main() {
    runMain();   
    return 0;
}
