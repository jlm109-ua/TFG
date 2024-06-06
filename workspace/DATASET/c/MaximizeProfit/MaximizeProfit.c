#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximizeProfit(int a[], int b[], int n, int m, int k) {
    int ans = m * k;

    for (int i = 0; i < n; i++)
        ans = (a[i] * b[i] * m) > ans ? (a[i] * b[i] * m) : ans;

    return ans;
}

int runMain(){
    int n = 5, m = 10, k = 3;
    int a[] = {2, 3, 4, 1, 5};
    int b[] = {1, 3, 2, 4, 5};

    return maximizeProfit(a, b, n, m, k);   
}

int main() {
    return runMain();
}
