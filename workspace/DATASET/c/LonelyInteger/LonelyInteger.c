// https://www.hackerrank.com/challenges/lonely-integer/problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lonelyinteger(int a[], int size) {
    if(size == 0) return 0;
    if(size == 1) return a[0];
    int numero = a[0];
    for(int i = 1 ; i < size; i++){
        numero = numero ^ a[i];        
    }
    return numero;
}

int runMain(){
     int res;

    int _a_size;
    _a_size = 3;
    int _a[] = {1, 1, 2};
    int az = 89;

    res = lonelyinteger(_a, _a_size);
    return res;
}

int main() {
    return runMain();
}
