#include "../exercise.h"

// FibonacciCache 结构体，用于缓存 Fibonacci 数列
struct FibonacciCache {
    unsigned long long cache[16];  // 缓存数组
    int cached;                    // 已缓存的最大索引
    // 构造函数初始化前两个 Fibonacci 数字
    FibonacciCache() : cached(2) {
        cache[0] = 0;
        cache[1] = 1;
    }
};

// 缓存优化的 Fibonacci 计算
static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    // 计算 Fibonacci 数字，直到缓存足够
    for (; cache.cached <= i; ++cache.cached) {
        cache.cache[cache.cached] = cache.cache[cache.cached - 1] + cache.cache[cache.cached - 2];
    }
    return cache.cache[i];  // 返回第 i 个 Fibonacci 数字
}

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib;
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
