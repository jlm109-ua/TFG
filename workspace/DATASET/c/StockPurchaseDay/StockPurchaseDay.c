#include <stdio.h>
#include <stdlib.h>

#define N 100005

int n = 8;
int arr[] = {4, 2, 2, 3, 3, 4, 6, 5};
int suffmn[N];
int q = 5;
int x;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int solve(int x) {
    int mx = -1;
    int lo = 1;
    int hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (suffmn[mid] <= x) {
            mx = max(mx, mid);
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return mx;
}

int runMain() {
    for (int i = 1; i <= n; ++i) {
        suffmn[i] = arr[i];
    }
    for (int i = n - 1; i >= 1; --i) {
        suffmn[i] = min(suffmn[i + 1], arr[i]);
    }
    while (q--) {
    }
    return EXIT_SUCCESS;
}

int main() {
    runMain();
    return 0;
}
