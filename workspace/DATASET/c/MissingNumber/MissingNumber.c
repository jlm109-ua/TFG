#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void printMissingNumbers(int arr1[], int n1, int arr2[], int n2) {
    int MAX = 10001; // Valor máximo para elementos en el arreglo (según el enunciado)
    int hash[MAX];
    memset(hash, 0, sizeof(hash));

    for (int i = 0; i < n1; i++) {
        hash[arr1[i]]++;
    }
    for (int i = 0; i < n2; i++) {
        hash[arr2[i]]--;
    }

    for (int i = 0; i < MAX; i++) {
        if (hash[i] < 0) {}
    }
}

void runMain() {
    int s1[] = {203, 204, 205, 206, 207, 208, 203, 204, 205, 206};
    int s2[] = {203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204};
    int N = sizeof(s1) / sizeof(s1[0]);
    int M = sizeof(s2) / sizeof(s2[0]);

    qsort(s1, N, sizeof(int), compare);
    qsort(s2, M, sizeof(int), compare);

    printMissingNumbers(s1, N, s2, M);
}

int main() {
    runMain();
    return 0;
}
