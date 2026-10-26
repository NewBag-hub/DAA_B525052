#include <stdio.h>
#define MAX 1000
int parent[MAX], sz[MAX], parity[MAX];
int find(int x) {
    if (parent[x] != x) {
        int old = parent[x];
        parent[x] = find(parent[x]);
        parity[x] ^= parity[old];
    }
    return parent[x];
}
/* Returns 1 if the edge is accepted, otherwise 0. */
int addEdge(int u, int v) {
    int ru = find(u);
    int pu = parity[u];
    int rv = find(v);
    int pv = parity[v];
    if (ru == rv)
        return (pu != pv);

    if (sz[ru] < sz[rv]) {
        int t = ru;
        ru = rv;
        rv = t;
    }
    parent[rv] = ru;
    parity[rv] = pu ^ pv ^ 1;
    sz[ru] += sz[rv];
    return 1;
}

int main(void) {
    int V, E, u, v;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        sz[i] = 1;
        parity[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge\n");
            continue;
        }
        if (addEdge(u, v))
            printf("Edge accepted\n");
        else
            printf("Edge rejected: graph would not be bipartite\n");
    }
    return 0;
}
