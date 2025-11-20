#include <iostream>
#include <chrono>
using namespace std;

long long rpower(long long x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

long long brpower(long long x, int n) {
    if (n == 0) return 1;
    long long y = brpower(x, n / 2);
    if (n % 2 == 0)
        return y * y;
    else
        return x * y * y;
}

int main() {
    int x = 2;
    int sizes[] = {1000, 2000, 3000, 4000, 7000};

    cout << "Comparing rpower and brpower:\n";
    for (int n : sizes) {
        auto start1 = chrono::high_resolution_clock::now();
        rpower(x, n);
        auto end1 = chrono::high_resolution_clock::now();
        double time1 = chrono::duration<double, milli>(end1 - start1).count();

        auto start2 = chrono::high_resolution_clock::now();
        brpower(x, n);
        auto end2 = chrono::high_resolution_clock::now();
        double time2 = chrono::duration<double, milli>(end2 - start2).count();

        cout << "n = " << n
             << " | rpower time = " << time1 << " ms"
             << " | brpower time = " << time2 << " ms" << endl;
    }

    return 0;
}
