#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005

int arr[33][MAX_N];
int brand[MAX_N];
int price[MAX_N];
int n;

void go(int x, int n){
    int count = 0;
    for(int i = 0; i < 6; i++){
        if((1 << i) & x){
            for(int j = 0; j < n; j++){
                if(brand[j] == i + 1){
                    arr[x][count++] = price[j];
                }
            }
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void runMain(){
    n = 3;
    brand[0] = 1; brand[1] = 1; brand[2] = 2;
    price[0] = 1; price[1] = 3; price[2] = 2;

    int q = 3;
    int queries[3][3] = {{1, 1, 2}, {2, 2, 1}, {1, 3, 1}};
    for(int q_index = 0; q_index < q; q_index++) {
        int d = queries[q_index][0];
        int x = 0;
        for(int j = 1; j <= d; j++){
            int a = queries[q_index][j];
            x += (1 << (a - 1));
        }
        int k = queries[q_index][d + 1];
        // Procesar la entrada
        for(int i = 0; i < 32; i++){
            go(i, n); // Llenar la matriz arr
            int arr_size = 0;
            while(arr[x][arr_size] != 0 && arr_size < n) arr_size++;
            qsort(arr[x], arr_size, sizeof(int), &compare);
            // Verificar si k es válido para esta combinación
            if(arr_size >= k) {
                // printf("%d\n", arr[x][k - 1]);
                break;
            }
        }
        // if(arr[x][0] == 0 || arr[x][k - 1] == 0) printf("-1\n");
    }
}

int main() {
    runMain();
    return 0;
}
