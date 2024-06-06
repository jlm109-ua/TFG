#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef long long int64;
typedef unsigned long long uint64;

#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

#define PI (acos(-1.0))
const double eps = 1e-11;

typedef struct {
    int *arr;
    int size;
} vector;

void vector_init(vector *v) {
    v->arr = NULL;
    v->size = 0;
}

void vector_push_back(vector *v, int x) {
    v->size++;
    v->arr = (int *)realloc(v->arr, v->size * sizeof(int));
    v->arr[v->size - 1] = x;
}

int vector_get(vector *v, int i) {
    return v->arr[i];
}

int n;
vector g[1 << 20];
int64 s1, s2;

int dfs(int p, int last, int d) {
    int s = 1;
    for (int i = 0; i < g[p].size; i++) {
        int x = vector_get(&g[p], i);
        if (x == last) continue;
        int c = dfs(x, p, d + 1);
        s += c;
        s1 += (int64)(n - c) * (d + 1);
        s2 += d + 1;
    }
    return s;
}

void runMain() {
    int n = 3;
    vector g[3];
    vector_init(&g[0]);
    vector_init(&g[1]);
    vector_init(&g[2]);
    vector_push_back(&g[0], 1);
    vector_push_back(&g[1], 0);
    vector_push_back(&g[0], 2);
    vector_push_back(&g[2], 0);

    s1 = s2 = 0;
    dfs(0, -1, 0);
}

int main() {
    runMain();
    return 0;
}