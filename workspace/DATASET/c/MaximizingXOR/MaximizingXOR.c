// problem statemtn is in https://www.hackerrank.com/challenges/maximizing-xor/problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxXor(int l, int r) {
    int nBitCount = 0;
    int p = l ^ r;
    while (p > 0) {
        p = p >> 1;
        ++nBitCount;
    }

    return (1 << nBitCount) - 1;
}

int runMain(){
    int res;
    int _l = 10;

    int _r = 15;

    int az = 89;
    return maxXor(_l, _r);
}

int main() {
    return runMain();
}