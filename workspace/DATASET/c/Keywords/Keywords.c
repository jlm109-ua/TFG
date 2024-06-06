#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAXVAL (int)1e9

int minimumLength(char *text, char **keys, int keys_len) {
    int answer = MAXVAL;
    strcat(text, " $");

    int text_len = strlen(text);

    int *m = (int *)calloc(keys_len, sizeof(int));
    char **m2 = (char **)calloc(text_len, sizeof(char *));
    for (int i = 0; i < text_len; ++i) {
        m2[i] = (char *)calloc(256, sizeof(char));
    }

    char word[256] = "";
    for (int i = 0, word_index = 0; i <= text_len; ++i) {
        if (text[i] == ' ') {
            for (int k = 0; k < keys_len; ++k) {
                if (strcmp(keys[k], word) == 0) {
                    if (m[k] != 0) {
                        memset(m2[m[k] - 1], 0, 256);
                    }
                    m[k] = i + 1;
                    strcpy(m2[i], word);
                }
            }
            word_index = 0;
            memset(word, 0, 256);
        } else {
            word[word_index++] = text[i];
        }
        int filled_keys = 0;
        for (int j = 0; j < keys_len; ++j) {
            if (m[j] != 0) {
                ++filled_keys;
            }
        }
        if (filled_keys == keys_len) {
            int mn = INT_MAX, sub = 0;
            for (int j = 0; j < text_len; ++j) {
                if (m2[j][0] != 0 && mn > j) {
                    mn = j;
                    sub = strlen(m2[j]);
                }
            }
            answer = (answer < i - mn + sub) ? answer : (i - mn + sub);
        }
    }

    if (answer == MAXVAL) {
        answer = -1;
    }

    free(m);
    for (int i = 0; i < text_len; ++i) {
        free(m2[i]);
    }
    free(m2);

    return answer;
}

int runMain() {
    char text[] = "why how what how when how when what";
    int keyWords = 2;

    char **keys = (char **)malloc(keyWords * sizeof(char *));
    keys[0] = (char *)malloc(256 * sizeof(char));
    keys[1] = (char *)malloc(256 * sizeof(char));

    strcpy(keys[0], "what");
    strcpy(keys[1], "when");

    int res = minimumLength(text, keys, keyWords);

    free(keys[0]);
    free(keys[1]);
    free(keys);

    return res;
}

int main() {
    return runMain();
}
