#include <iostream>

// recursive fibonacci function
int fibonacci(int const n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// iterative fibonacci function
int fibonacci_iterative(int const n) {
    int first = 0, second = 1;
    if (n == 0) {
        return 0;
    }
    for (int i = 2; i <= n; i++) {
        int result = first + second;
        first = second;
        second = result;
    }
    return second;
}

// Recursive Approach with Memoization
int fibonacci_memoization(int const n, int *memo) {
    if (n <= 1) {
        return n;
    }
    if (memo[n] != -1) {
        return memo[n];
    }
    memo[n] = fibonacci_memoization(n - 1, memo) + fibonacci_memoization(n - 2, memo);
    return memo[n];
}

// Tail Recursive Approach
int fibonacci_tail_recursive(int const n, int const a = 0, int const b = 1) {
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }
    return fibonacci_tail_recursive(n - 1, b, a + b);
}

int main() {
    int n = 10;
    int memo[n + 1];
    for (int i = 0; i < n + 1; i++) {
        memo[i] = -1;
    }
    int result = fibonacci_tail_recursive(n);
    std::cout << "Fibonacci of " << n << " is " << result << std::endl;
    return 0;
}