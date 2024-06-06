#include <stdio.h>

int lowestTriangle(int base, int area) {
    int h;
    h = 2 * area / base;
    if ((h * base / 2) < area) {
        h += 1;
    }
    return h;
}

int runMain(){
    int base = 17;
    int area = 100;
    return lowestTriangle(base, area);
}

int main() {
    return runMain();
}