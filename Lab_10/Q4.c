#include <stdio.h>
#define MAX 100000
int parent[MAX], sz[MAX], active[MAX];
long long weight[MAX], sum[MAX];
int eu[MAX * 2], ev[MAX * 2];
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
long long getMax(int n) {
    long long best = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (active[i] && find(i) == i) {
            if (!found || sum[i] > best)
                best = sum[i];
            found = 1;
        }
    }
    return found ? best : 0;
}
int main(void) {
    int n, m;
    static int order[MAX], ans_dummy;
    long long answer[MAX];
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);
    if (n <= 0 || n > MAX || m < 0 || m > 2 * MAX) {
        printf("Invalid input\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &weight[i]);
        parent[i] = i;
        sz[i] = 1;
        sum[i] = 0;
        active[i] = 0;
    }
    for (int i = 0; i < m; i++)
        scanf("%d %d", &eu[i], &ev[i]);
    printf("Enter deletion order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &order[i]);
        if (order[i] < 0 || order[i] >= n) {
            printf("Invalid deletion order\n");
            return 1;
        }
    }
    /* After the final deletion, no vertices remain. */
    answer[n - 1] = 0;
    for (int i = n - 1; i >= 1; i--) {
        int u = order[i];
        active[u] = 1;
        sum[u] = weight[u];
        for (int j = 0; j < m; j++) {
            int a = eu[j], b = ev[j];
            if (a < 0 || a >= n || b < 0 || b >= n) {
                printf("Invalid edge\n");
                return 1;
            }
            if (a == u && active[b])
                unite(a, b);
            else if (b == u && active[a])
                unite(a, b);
        }
        answer[i - 1] = getMax(n);
    }
    printf("Maximum component weight after each deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%lld\n", answer[i]);
    return 0;
}
