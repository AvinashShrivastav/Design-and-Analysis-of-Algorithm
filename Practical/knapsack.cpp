#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Test case
    int W = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int n = val.size();

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}