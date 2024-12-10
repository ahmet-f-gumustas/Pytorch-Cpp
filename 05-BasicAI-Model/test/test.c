#include <stdio.h>
#include <time.h>

#define ITERATIONS 1000000000

int main() {
    clock_t start, end;
    double cpu_time_used;
    volatile double result = 0.0;

    start = clock();
    for(long i = 0; i < ITERATIONS; i++) {
        result += (double)i * (double)i;
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("C: Sonuç = %f, Süre = %f saniye\n", result, cpu_time_used);
    return 0;
}

