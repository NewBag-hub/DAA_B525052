#include <stdio.h>
#include <stdlib.h>
int *parent, *sz;
int R, C;
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
int unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
        return 0;
    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}
int main(void) {
    int K;
    printf("Enter rows, columns and operations: ");
    scanf("%d %d %d", &R, &C, &K);
    int N = R * C;
    parent = malloc((size_t)N * sizeof(int));
    sz = malloc((size_t)N * sizeof(int));
    int *land = calloc((size_t)N, sizeof(int));
    if (parent == NULL || sz == NULL || land == NULL) {
        printf("Memory allocation failed.\n");
        free(parent);
        free(sz);
        free(land);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    int islands = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    printf("Enter each land position (row column):\n");
    for (int i = 0; i < K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        if(r < 0 || r >= R || c < 0 || c >= C){
            printf("Invalid position\n");
            continue;
        }
        int id = r * C + c;
        if(land[id]){
            printf("%d\n", islands);
            continue;
        }
        land[id] = 1;
        islands++;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= R ||
                nc < 0 || nc >= C)
                continue;
            int nid = nr * C + nc;
            if(land[nid]){
                if(unite(id, nid))
                    islands--;
            }
        }
        printf("%d\n", islands);
    }
    free(parent);
    free(sz);
    free(land);
    return 0;
}
