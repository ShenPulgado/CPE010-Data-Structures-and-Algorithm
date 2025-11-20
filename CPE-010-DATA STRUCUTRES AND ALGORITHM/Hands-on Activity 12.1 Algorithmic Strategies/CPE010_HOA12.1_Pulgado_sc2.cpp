#include <bits/stdc++.h>
using namespace std;

int getMinSteps(int n) {
    vector<int> dp(n + 1);
    dp[1] = 0;             

    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
        if (i % 2 == 0) dp[i] = min(dp[i], 1 + dp[i / 2]);
        if (i % 3 == 0) dp[i] = min(dp[i], 1 + dp[i / 3]);
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << "Minimum steps to 1: " << getMinSteps(n);
    return 0;
}

