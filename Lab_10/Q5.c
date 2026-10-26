#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int parent[MAX], sz[MAX];
int A[MAX], result[MAX];
int positions[MAX], values[MAX];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (sz[u] < sz[v]) {
        int t = u;
        u = v;
        v = t;
    }
    parent[v] = u;
    sz[u] += sz[v];
}
int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}
int main(void) {
    int n, m;
    printf("Enter n and number of edges: ");
    scanf("%d %d", &n, &m);
    if (n <= 0 || n > MAX || m < 0) {
        printf("Invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        parent[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            return 1;
        }
        unite(u, v);
    }
    int visited[MAX] = {0};
    for (int i = 0; i < n; i++) {
        int root = find(i);
        if (visited[root])
            continue;
        visited[root] = 1;
        int pCount = 0, vCount = 0;
        for (int j = 0; j < n; j++) {
            if (find(j) == root) {
                positions[pCount++] = j;
                values[vCount++] = A[j];
            }
        }
        qsort(positions, pCount, sizeof(int), cmp);
        qsort(values, vCount, sizeof(int), cmp);

        for (int j = 0; j < pCount; j++)
            result[positions[j]] = values[j];
    }
    printf("Lexicographically smallest permutation:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
    return 0;
}
