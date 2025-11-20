#include <bits/stdc++.h>
using namespace std;

int getMinSteps(int n, vector<int>& memo) {
    if (n == 1) return 0;
    if (memo[n] != -1) return memo[n];

    int r = 1 + getMinSteps(n - 1, memo);
    if (n % 2 == 0) r = min(r, 1 + getMinSteps(n / 2, memo));
    if (n % 3 == 0) r = min(r, 1 + getMinSteps(n / 3, memo));

    return memo[n] = r;
}

int main() {
    int n;
    cin >> n;
    vector<int> memo(n + 1, -1);
    cout << "Minimum steps to 1: " << getMinSteps(n, memo);
}
