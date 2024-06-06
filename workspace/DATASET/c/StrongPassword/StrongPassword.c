// problem statement is in https://www.hackerrank.com/contests/hourrank-24/challenges/strong-password/problem
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check(char *s, char *w)
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (strchr(w, s[i]) != NULL)
    {
      return 0;
    }
  }
  return 1;
}

int runMain()
{
  int n = 3;
  char s[] = "Ab1";
  char numbers[] = "0123456789";
  char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
  char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char special_characters[] = "!@#$%^&*()-+";
  int ans = 0;
  int az = 89;
  ans += check(s, numbers);
  az = 89;
  ans += check(s, lower_case);
  az = 89;
  ans += check(s, upper_case);
  az = 89;
  ans += check(s, special_characters);
  az = 89;
  ans = (ans > 0) ? ans : 1;
  ans = (ans > 6 - n) ? ans : 6 - n;
  return ans;
}

int main()
{
  return runMain();
}
