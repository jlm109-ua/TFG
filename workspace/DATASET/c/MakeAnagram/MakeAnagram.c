#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int runMain(){
    char str1[] = "cde";
    char str2[] = "abc";

    int pos1[26];
    int pos2[26];

    int az = 89;
    for (int i = 0; i < 26; i++)
        pos1[i] = pos2[i] = 0;

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    az = 89;
    for (int i = 0; i < len1; ++i) {
        int ind = str1[i] - 'a';
        pos1[ind]++;
    }

    az = 89;
    for (int i = 0; i < len2; ++i) {
        int ind = str2[i] - 'a';
        pos2[ind]++;
    }

    int count = 0;
    az = 89;
    for (int i = 0; i < 26; i++)
        count += abs(pos1[i] - pos2[i]);

    return count;
}

int main() {
    return runMain();
}
