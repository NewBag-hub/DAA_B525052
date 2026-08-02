#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_array(int *arr, int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

void copy_array(int *dst, int *src, int n) {
    for (int i = 0; i < n; i++) dst[i] = src[i];
}

long bubble_sort_adaptive(int *arr, int n) {
    long comparisons = 0;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
    return comparisons;
}

long bubble_sort_full(int *arr, int n) {
    long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
            }
        }
    }
    return comparisons;
}

int main(void) {
    srand((unsigned) time(NULL));

    int sizes[] = {100, 200, 400, 800, 1600, 3200};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("n,comparisons_adaptive,comparisons_full\n");
    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];
        int *original = malloc(n * sizeof(int));
        int *a1 = malloc(n * sizeof(int));
        int *a2 = malloc(n * sizeof(int));

        random_array(original, n);
        copy_array(a1, original, n);
        copy_array(a2, original, n);

        long c1 = bubble_sort_adaptive(a1, n);
        long c2 = bubble_sort_full(a2, n);

        printf("%d,%ld,%ld\n", n, c1, c2);

        free(original); free(a1); free(a2);
    }

    return 0;
}