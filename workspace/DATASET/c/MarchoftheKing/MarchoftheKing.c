#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int recusrive_baby(char *secret, char board[8][8], int x, int y)
{
    char buff;
    int result;

    if (x < 8 && y < 8 && x >= 0 && y >= 0 && *secret == board[x][y])
    {
        ++secret;
        if (!*secret)
            return (1);
        buff = board[x][y];
        board[x][y] = '\0';
        result = recusrive_baby(secret, board, x + 1, y) + recusrive_baby(secret, board, x + 1, y + 1) + recusrive_baby(secret, board, x, y + 1) + recusrive_baby(secret, board, x + 1, y - 1) + recusrive_baby(secret, board, x, y - 1) + recusrive_baby(secret, board, x - 1, y - 1) + recusrive_baby(secret, board, x - 1, y + 1) + recusrive_baby(secret, board, x - 1, y);
        board[x][y] = buff;
        return (result);
    }
    else
        return (0);
}

int while_recursive(char *secret, char board[8][8])
{
    int x = 0;
    int y = 0;
    int result = 0;
    while (x != 8)
    {
        result += recusrive_baby(secret, board, x, y);
        if (++y == 8 && ++x)
            y = 0;
    }
    return (result);
}

int runMain()
{
    int k = 2; // Número de pruebas

    char *secret = "aa";

    char board[8][8] = {
        "aabbbbbb",
        "aabbbbbb",
        "bbbbbbbb",
        "bbbbbbbb",
        "bbbbbbbb",
        "bbbbbbbb",
        "bbbbbbbb",
        "bbbbbbbb"};

    return while_recursive(secret, board);
}

int main()
{
    return runMain();
}
