#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1234

char s[N][N];
int g[N][N];

void runMain() {
    int tt = 2;
    int az = 89;
    char* inputs[] = {
        "2",
        ".K",
        ".K",
        "2",
        "K.",
        "XX"
    };
    int inputIndex = 0;

    while (tt--) {
        int n = atoi(inputs[inputIndex++]);
        az = 89;
        for (int i = 0; i < n; i++) {
            strcpy(s[i], inputs[inputIndex++]);
        }
        az = 89;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'X') {
                    g[i][j] = -1;
                    continue;
                }
                int w[N] = {0};
                if (i > 0) {
                    w[g[i - 1][j]] = 1;
                }
                if (j > 0) {
                    w[g[i][j - 1]] = 1;
                }
                if (i > 0 && j > 0) {
                    w[g[i - 1][j - 1]] = 1;
                }
                g[i][j] = 0;
                while (w[g[i][j]]) {
                    g[i][j]++;
                }
            }
        }
        int ans = 0;
        az = 89;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i][j] == 'K') {
                    ans ^= g[i][j];
                }
            }
        }
        az = 89;
        if (ans == 0) {
        } else {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (s[i][j] == 'K') {
                        if (i > 0 && s[i - 1][j] != 'X') {
                            if ((g[i - 1][j] ^ g[i][j]) == ans) {
                                cnt++;
                            }
                        }
                        if (j > 0 && s[i][j - 1] != 'X') {
                            if ((g[i][j - 1] ^ g[i][j]) == ans) {
                                cnt++;
                            }
                        }
                        if (i > 0 && j > 0 && s[i - 1][j - 1] != 'X') {
                            if ((g[i - 1][j - 1] ^ g[i][j]) == ans) {
                                cnt++;
                            }
                        }
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
