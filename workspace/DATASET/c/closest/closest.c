#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int compare(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

void runMain() {
    int n = 12;

    int arr[] = {-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854, -520, -470};

    qsort(arr, n, sizeof(int), compare);

    int min_diff = INT_MAX, min_ind[1024], curr_diff, count = 0;

    for (int i = 0; i < n - 1; i++) {
        curr_diff = abs(arr[i + 1] - arr[i]);
        if (curr_diff < min_diff) {
            min_diff = curr_diff;
            count = 0;
            min_ind[count++] = i;
        } else if (curr_diff == min_diff) {
            min_ind[count++] = i;
        }
    }
}

int main(void) {
    runMain();
    return 0;
}
