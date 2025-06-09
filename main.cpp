#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

// Attribute macros
#if defined(_MSC_VER)
    #define ALWAYS_INLINE __forceinline
    #define NOINLINE      __declspec(noinline)
#else
    #define ALWAYS_INLINE inline __attribute__((always_inline))
    #define NOINLINE      __attribute__((noinline))
#endif

int generateRandomNumber(int min, int max) {
    static std::random_device rd; 
    static std::mt19937 eng(rd()); 
    std::uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

// Inline and noinline functions
ALWAYS_INLINE int square_inline(int x) {
    return x * x;
}

NOINLINE int square_noinline(int x) {
    return x * x;
}

// Use the square functions
int sum_inline(const std::vector<int>& v) {
    int result = 0;
    for (int x : v)
        result += square_inline(x);
    return result;
}

int sum_noinline(const std::vector<int>& v) {
    int result = 0;
    for (int x : v)
        result += square_noinline(x);
    return result;
}

int main() {
    constexpr size_t N = 100'000'000;
    std::vector<int> data(N);

    std::generate(data.begin(), data.end(), []() { return generateRandomNumber(1, 100); });    

    auto start = std::chrono::high_resolution_clock::now();
    int s1 = sum_inline(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Inline sum:   " << s1 << " in "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << "\n";

    start = std::chrono::high_resolution_clock::now();
    int s2 = sum_noinline(data);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Noinline sum: " << s2 << " in "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start) << "\n";

    return 0;
}