#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int runMain() {
   int n = 6;
  int h[] = {2, 5, 1, 3, 5, 4};
  int connections[][2] = {{1, 2}, {1, 3}, {5, 2}, {6, 4}, {4, 2}};

  int *b = malloc(sizeof(bool) * n);
  for (int i = 0; i < n; i++)
    b[i] = false;

  int result = 0;
  for (int a0 = 0; a0 < n - 1; a0++)
  {
    int x = connections[a0][0] - 1;
    int y = connections[a0][1] - 1;

    if (x > y)
    {
      int temp = x;
      x = y;
      y = temp;
    }
    if (h[x] > h[y])
    {
      h[x] = h[y];
      b[x] = true;
    }
  }

  for (int i = 0; i < n; i++)
    if (b[i])
      result++;

  free(b);
  return result;
}

int main()
{
  return runMain();
}