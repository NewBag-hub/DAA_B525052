#include <stdio.h>
#define MAX 100000
int parent[MAX], sz[MAX];
long long sum[MAX];

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
    sum[u] += sum[v];
}
long long maximum(int n, int K) {
    long long best = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (find(i) == i && sz[i] <= K) {
            if (!found || sum[i] > best)
                best = sum[i];

            found = 1;
        }
    }
    return found ? best : 0;
}

int main(void) {
    int n, e, K;
    printf("Enter vertices, edges and K: ");
    scanf("%d %d %d", &n, &e, &K);
    if (n <= 0 || n > MAX || e < 0 || K < 0) {
        printf("Invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        long long w;
        scanf("%lld", &w);
        parent[i] = i;
        sz[i] = 1;
        sum[i] = w;
    }
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            continue;
        }
        unite(u, v);
        printf("Maximum weight = %lld\n", maximum(n, K));
    }
    return 0;
}
