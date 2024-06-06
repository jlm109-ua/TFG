// problem statement is in nhttps://www.hackerrank.com/contests/university-codesprint-3/challenges/erupting-volcanoes/problem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1234567


int x[N], y[N], w[N];

int runMain()
{
int n = 10;  // Valor predefinido para n
  int m = 1;   // Valor predefinido para m

  int x_values[] = {4};    // Valores predefinidos para x
  int y_values[] = {5};    // Valores predefinidos para y
  int w_values[] = {6};    // Valores predefinidos para w

  int ans = 0;

  for (int i = 0; i < m; i++) {
    x[i] = x_values[i];
    y[i] = y_values[i];
    w[i] = w_values[i];
  }

  for (int xx = 0; xx < n; xx++) {
    for (int yy = 0; yy < n; yy++) {
      int cur = 0;
      for (int i = 0; i < m; i++) {
        int d = abs(x[i] - xx) > abs(y[i] - yy) ? abs(x[i] - xx) : abs(y[i] - yy);
        cur += w[i] - d > 0 ? w[i] - d : 0;
      }
      ans = cur > ans ? cur : ans;
    }
  }

  return ans;
}

int main()
{
  return runMain();
}
