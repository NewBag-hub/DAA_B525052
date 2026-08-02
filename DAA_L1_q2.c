#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int toss(double p) {
    double r = (double) rand() / ((double) RAND_MAX + 1.0);
    return (r < p) ? 1 : 0;
}

double simulate(double p, long n) {
    long heads = 0;
    for (long i = 0; i < n; i++) {
        heads += toss(p);
    }
    return (double) heads / (double) n;
}

int main(void) {
    srand((unsigned) time(NULL));

    long trial_sizes[] = {100, 1000, 10000, 100000, 1000000};
    int num_trials = sizeof(trial_sizes) / sizeof(trial_sizes[0]);

    printf("FAIR COIN (p = 0.5)\n");
    printf("%-10s %-15s\n", "N", "P(HEAD) observed");
    for (int i = 0; i < num_trials; i++) {
        double observed = simulate(0.5, trial_sizes[i]);
        printf("%-10ld %-15.5f\n", trial_sizes[i], observed);
    }

    double biased_p = 0.7;
    printf("\nBIASED COIN (true p = %.2f)\n", biased_p);
    printf("%-10s %-15s\n", "N", "P(HEAD) observed");
    for (int i = 0; i < num_trials; i++) {
        double observed = simulate(biased_p, trial_sizes[i]);
        printf("%-10ld %-15.5f\n", trial_sizes[i], observed);
    }

    return 0;
}
