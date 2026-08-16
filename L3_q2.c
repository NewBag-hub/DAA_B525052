#include <stdio.h>

#define MAXN 10000

int prefix[MAXN + 1];

void build_prefix(int *arr, int n) {
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];
}

int weight_of_array(int p, int q) {
    if (p > q) return 0;
    return prefix[q + 1] - prefix[p];
}

int lighter_coin(int *arr, int p, int q, int normal_weight) {
    if (p == q) {
        if (*(arr + p) < normal_weight) return p;
        return -1;
    }
    if (p > q) return -1;

    int mid  = p + (q - p - 1) / 2;

    int left = (q - p + 1) % 2;
    int w1 = weight_of_array(p, mid), w2 = weight_of_array(mid + 1, q - left);

    if (left) {
        if (*(arr + q) < normal_weight) return q;
    }

    if (w1 == w2) return -1;
    else if (w1 < w2) return lighter_coin(arr, p, mid, normal_weight);
    else return lighter_coin(arr, mid + 1, q - left, normal_weight);
}

int main() {
    int arr[] = {10,10,10,10,10,10,10,10,10,10}; //Test weights of 10 coins
    int n = sizeof(arr) / sizeof(arr[0]);

    build_prefix(arr, n);

    int idx = lighter_coin(arr, 0, n - 1, 10);
    printf(idx != -1 ? "Found at %d\n" : "Not Found\n", idx);

    int arr2[] = {10,10,10,10,10,10,10,9,10,10}; //Test weights of 10 coins
    build_prefix(arr2, n);

    idx = lighter_coin(arr2, 0, n - 1, 10);
    printf(idx != -1 ? "Found at %d\n" : "Not Found\n", idx);

    return 0;
}