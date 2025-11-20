#include <iostream>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciLoop(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, next;
    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;       
        b = next;
    }
    return b;
}

int main() {
    int n = 10;
    std::cout << "Recursive Fibonacci (" << n << ") = " 
              << fibonacci(n) << "\n";
    
    int x = 10;
    std::cout << "Iterative Fibonacci (" << n << ") = " 
              << fibonacciLoop(n) << "\n";
}