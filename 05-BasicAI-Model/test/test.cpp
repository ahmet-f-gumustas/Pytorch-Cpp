#include <iostream>
#include <chrono>

#define ITERATIONS 1000000000

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    volatile double result = 0.0;

    for(long i = 0; i < ITERATIONS; i++) {
        result += static_cast<double>(i) * static_cast<double>(i);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "C++: Sonuç = " << result << ", Süre = " << elapsed.count() << " saniye\n";
    return 0;
}

