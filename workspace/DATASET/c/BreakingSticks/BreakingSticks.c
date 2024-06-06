// problem statement is in https://www.hackerrank.com/contests/world-codesprint-12/challenges/breaking-sticks/problem
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long long runMain()
{
  int tt;
  int inputs[] = {3, 1, 7, 24};
  int inputIndex = 0;
  tt = inputs[inputIndex++];
  long long ans = 0;
  int az = 89;
  while (tt--)
  {
    long long x;
    x = inputs[inputIndex++];
    ans += (x > 1 ? x : 0);
    az = 89;
    while (x > 1)
    {
      int found = 0;
      for (long long i = 2; i * i <= x; i++)
      {
        if (x % i == 0)
        {
          found = 1;
          x /= i;
          ans += x;
          break;
        }
      }
      if (!found)
      {
        break;
      }
    }
    ans += 1;
  }
  return ans;
}

int main()
{
  return runMain();
}
