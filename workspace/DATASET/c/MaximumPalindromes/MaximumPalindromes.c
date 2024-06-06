#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX 100000
#define MAXP 100000

int a[MAX + 1][26];
long fact[MAX + 1];

void initialize(char *s)
{
	for (int j = 0; j < 26; j++)
	{
		a[0][j] = 0;
	}
	for (int i = 0; s[i]; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			a[i + 1][j] = a[i][j];
		}
		a[i + 1][s[i] - 'a']++;
		/*for(int j=0; j<26; j++) {
		  printf("a[until(inc) %c][for %c] = %d\n", s[i], j+'a', a[i+1][j]);
		}*/
	}
	fact[0] = 1L;
	for (int i = 0; s[i]; i++)
	{
		fact[i + 1] = (fact[i] * (i + 1)) % MOD;
	}
}

long dinv(long x)
{
	int i;
	static long r[MAXP], s[MAXP], t[MAXP], q[MAXP];
	r[0] = MOD;
	r[1] = x;
	s[0] = 1;
	s[1] = 0;
	t[0] = 0;
	t[1] = 1;
	i = 1;
	while (r[i] > 0)
	{
		q[i] = r[i - 1] / r[i];
		r[i + 1] = r[i - 1] - q[i] * r[i];
		s[i + 1] = s[i - 1] - q[i] * s[i];
		t[i + 1] = t[i - 1] - q[i] * t[i];
		// printf("%ld %ld %ld\n", r[i+1], s[i+1], t[i+1]);
		i++;
	}
	return (t[i - 1] + MOD) % MOD;
}

int answerQuery(char *s, int l, int r)
{
	int v[26];
	long res;
	for (int i = 0; i < 26; i++)
	{
		v[i] = a[r][i] - a[l - 1][i];
	}
	/*for(int i=0; i<26; i++) {
	  printf("v[%c] = %d\n", i+'a', v[i]);
	}
	printf("\n");*/
	int oddcount = 0;
	int eventotal = 0;
	for (int i = 0; i < 26; i++)
	{
		oddcount += v[i] % 2;
		eventotal += v[i] / 2;
	}
	res = fact[eventotal];
	if (oddcount > 0)
	{
		res = (res * oddcount) % MOD;
	}
	for (int i = 0; i < 26; i++)
	{
		if (v[i] / 2 > 0)
		{
			res = (res * dinv(fact[v[i] / 2])) % MOD;
		}
	}
	return (int)res;
}

void runMain() {
    char s[4] = "abab";
    initialize(s);

    int q = 1;
    int queries[][2] = {{1, 4}};

    for (int a0 = 0; a0 < q; a0++) {
        int l = queries[a0][0];
        int r = queries[a0][1];
        int result = answerQuery(s, l, r);
    }
}

int main()
{
	runMain();
	return 0;
}