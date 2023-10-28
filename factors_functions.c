#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

void trial_division(long int n) {
    long int f;

    if (n % 2 == 0) {
        printf("%ld=%ld*%d\n", n, n / 2, 2);
        return;
    }

    f = 3;
    while (f * f <= n) {
        if (n % f == 0) {
            printf("%ld=%ld*%ld\n", n, n / f, f);
            return;
        }
        else {
            f += 2;
        }
    }
    printf("%ld=%ld*%d\n", n, n, 1);
}

void print_factors() {
    FILE* prime = fopen("prime.txt", "r");
    long int n;
    if (prime) {
        while (fscanf(prime, "%ld", &n) != EOF) {
            trial_division(n);
        }
        fclose(prime);
    }
}

int main() {
    struct timeval start_time, end_time;
    struct rusage start_resources, end_resources;

    gettimeofday(&start_time, NULL);
    getrusage(RUSAGE_SELF, &start_resources);
    
    print_factors();
    
    getrusage(RUSAGE_SELF, &end_resources);
    gettimeofday(&end_time, NULL);

    long int duration_sec = end_time.tv_sec - start_time.tv_sec;
    long int duration_usec = end_time.tv_usec - start_time.tv_usec;
    float duration = duration_sec + duration_usec / 1000000.0;

    printf("\nreal: %.6f\nuser: %.6f\nsys: %.6f\n",
           duration,
           (end_resources.ru_utime.tv_sec - start_resources.ru_utime.tv_sec) +
           (end_resources.ru_utime.tv_usec - start_resources.ru_utime.tv_usec) / 1000000.0,
           (end_resources.ru_stime.tv_sec - start_resources.ru_stime.tv_sec) +
           (end_resources.ru_stime.tv_usec - start_resources.ru_stime.tv_usec) / 1000000.0);

    return 0;
}

