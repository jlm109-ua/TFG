#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005

int wx[MAXN], wy[MAXN];

int cmp(const void* a, const void* b) {
    return *(const int*)a - *(const int*)b;
}

void runMain() {
    int inputs[][2] = {{4, 3}, {4, 4}, {4, 5}, {4, 6}};
    char s[] = "RGBW";

    int t = 4; // Número de casos de prueba
    for (int a0 = 0; a0 < t; a0++) {
        int n = inputs[a0][0];
        int j = inputs[a0][1];

        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' || s[i] == 'B')
                wx[i] = j;
            else
                wy[i] = j;
        }

        int m = 0;
        for (int i = 0; i < n; i++)
            if (wy[i])
                wy[m++] = wy[i];

        qsort(wx, n, sizeof(int), cmp);
        qsort(wy, m, sizeof(int), cmp);

        int ans = m;
        j = 0;
        if (n > m) {
            if (wx[0] < wy[0])
                ans++, j++;
            if (wx[n-1] > wy[m-1])
                ans++;
        }
        else if (wx[0] < wy[0])
            ans++, j++;
        else if (wx[n-1] > wy[m-1])
            ans++;

        for (int i = 0; i < m-1; i++) {
            while (j < n && wx[j] < wy[i])
                j++;
            if (j < n && wx[j] > wy[i] && wx[j] < wy[i+1])
                ans++;
        }
    }
}

int main() {
    runMain();
    return 0;
}
