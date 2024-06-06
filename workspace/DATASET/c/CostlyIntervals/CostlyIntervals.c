#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 101010
#define MAXBIT 31
#define NV (1 << 18)

typedef int V;
typedef struct
{
	V val[NV * 2];
} SegTree;

int N=5;
int K=6;
int A[MAXN] = {2, 4, 3, 1, 7};
SegTree stma, stmi, stor, stand;

V max(V a, V b) { return a > b ? a : b; }
V min(V a, V b) { return a < b ? a : b; }
V or (V a, V b) { return a | b; }
V and (V a, V b) { return a & b; }

void init_st(SegTree *st) { memset(st->val, 0, sizeof(st->val)); }

void update_st(SegTree *st, int (*comp)(V, V), int entry, V v)
{
	entry += NV;
	st->val[entry] = v;
	while (entry > 1)
	{
		entry >>= 1;
		st->val[entry] = comp(st->val[entry * 2], st->val[entry * 2 + 1]);
	}
}

V getval_st(SegTree *st, int (*comp)(V, V), int x, int y, int l, int r, int k)
{
	if (r <= x || y <= l)
		return comp == max ? 0 : (comp == min ? (1 << 30) : (comp == and? 0x7FFFFFFF : 0));
	if (x <= l && r <= y)
		return st->val[k];
	return comp(getval_st(st, comp, x, y, l, (l + r) / 2, k * 2), getval_st(st, comp, x, y, (l + r) / 2, r, k * 2 + 1));
}

int nex[MAXBIT][2];
int ret[MAXN];
int *add[MAXN], *del[MAXN];
int add_size[MAXN], del_size[MAXN];
int cand_buffer[MAXN][MAXBIT * 2];

void runMain(){
	for (int i = 0; i < N; i++)
	{
		update_st(&stma, max, i, A[i]);
		update_st(&stmi, min, i, A[i]);
		update_st(&stor, or, i, A[i]);
		update_st(&stand, and, i, A[i]);
	}

	for (int i = 0; i < MAXBIT; i++)
		nex[i][0] = nex[i][1] = N;

	for (int i = N - 1; i >= 0; i--)
	{
		int *cand = cand_buffer[i];
		int cand_size = 0;
		for (int j = 0; j < MAXBIT; j++)
		{
			if (A[i] & (1 << j))
				nex[j][1] = i;
			else
				nex[j][0] = i;
			cand[cand_size++] = nex[j][0];
			cand[cand_size++] = nex[j][1];
		}

		int y = -1;
		for (int e = 0; e < cand_size; e++)
		{
			int x = cand[e];
			if (x == N)
				continue;
			int ma = getval_st(&stma, max, i, x + 1, 0, NV, 1);
			int mi = getval_st(&stmi, min, i, x + 1, 0, NV, 1);
			int mor = getval_st(&stor, or, i, x + 1, 0, NV, 1);
			int mand = getval_st(&stand, and, i, x + 1, 0, NV, 1);
			int val = mor - mand - (ma - mi);
			if (val >= K)
			{
				y = x;
			}
		}

		if (y == -1)
			continue;

		for (int j = 19; j >= 0; j--)
		{
			if (y + (1 << j) >= N)
				continue;
			y += (1 << j);
			int ma = getval_st(&stma, max, i, y + 1, 0, NV, 1);
			int mi = getval_st(&stmi, min, i, y + 1, 0, NV, 1);
			int mor = getval_st(&stor, or, i, y + 1, 0, NV, 1);
			int mand = getval_st(&stand, and, i, y + 1, 0, NV, 1);
			int val = mor - mand - (ma - mi);
			if (val < K)
				y -= (1 << j);
		}

		int len = y - i + 1;
		add[i] = realloc(add[i], (++add_size[i]) * sizeof(int));
		add[i][add_size[i] - 1] = len;
		del[y + 1] = realloc(del[y + 1], (++del_size[y + 1]) * sizeof(int));
		del[y + 1][del_size[y + 1] - 1] = len;
	}

	memset(ret, -1, sizeof(ret));
	int max_len = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < add_size[i]; j++)
		{
			if (add[i][j] > max_len)
				max_len = add[i][j];
		}
		for (int j = 0; j < del_size[i]; j++)
		{
			if (del[i][j] == max_len)
				max_len--;
		}
	}

}

int main()
{
	runMain();
	return 0;
}
