#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void runMain() {
    int T = 2;
    char str1[2][1001] = {"hello\n", "hi\n"};
    char str2[2][1001] = {"world\n", "world\n"};

    for (int t = 0; t < T; t++) {
        int count[256];
        for (int i = 0; i < 256; ++i)
            count[i] = 0;

        int nLen = strlen(str1[t]);
        for (int i = 0; i < nLen; ++i)
            count[str1[t][i] - 'a']++;

        nLen = strlen(str2[t]);
        char res[4] = "NO";
        for (int i = 0; i < nLen; ++i) {
            if (count[str2[t][i] - 'a'] != 0) {
                strcpy(res, "YES");
                break;
            }
        }
    }
}

int main() {
    runMain();
    return 0;
}