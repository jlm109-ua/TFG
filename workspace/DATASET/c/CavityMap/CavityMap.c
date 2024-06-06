#include <stdio.h>

void runMain() {
    int n = 4; // Tamaño de la matriz

    char arr[4][5] = { // Matriz de entrada
        "1112",
        "1912",
        "1892",
        "1234"
    };

    int count = 0;
    int vect[n*n]; // Utilizamos un solo arreglo para almacenar las posiciones de las cavidades

    // Iteramos sobre todas las celdas internas de la matriz
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            // Verificamos si la celda es una cavidad
            if (arr[i][j] > arr[i-1][j] && arr[i][j] > arr[i+1][j] &&
                arr[i][j] > arr[i][j-1] && arr[i][j] > arr[i][j+1]) {
                vect[count++] = i * n + j; // Guardamos la posición de la cavidad
            }
        }
    }

    // Marcamos las cavidades en la matriz original
    for (int i = 0; i < count; i++) {
        int row = vect[i] / n; // Fila de la cavidad
        int col = vect[i] % n; // Columna de la cavidad
        arr[row][col] = 'X';
    }
}

int main() {
    runMain();
    return 0;
}
