#include <iostream>
#include <vector>
#include <chrono>
#include <random>

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j])
                return false;
        }
    }
    return true;
}

std::vector<int> generate_random_array(int n, int max_value = 1000000) {
    std::vector<int> arr(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, max_value);

    for (int i = 0; i < n; i++)
        arr[i] = dist(gen);

    return arr;
}

void run_experiment(int n) {
    auto A = generate_random_array(n);

    auto start = std::chrono::high_resolution_clock::now();
    bool result = Unique(A);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Input size (n): " << n 
              << " → Time taken: " << duration.count() << " ms"
              << " → Result: " << (result ? "Unique" : "Duplicate Found")
              << std::endl;
}

int main() {
    std::cout << "Experimental Analysis of Unique(A) Algorithm" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    run_experiment(1000);
    run_experiment(4000);
    run_experiment(16000);

    return 0;
}
