#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem using dynamic programming
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    // Initialize a 2D vector to store the results of subproblems
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the dp table iteratively
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            // If the current item's weight is less than or equal to the current capacity
            if (wt[i - 1] <= w) {
                // Choose the maximum between including and excluding the current item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                // If including the current item exceeds the capacity, skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    // Test case
    int W = 50; // Knapsack capacity
    vector<int> val = {60, 100, 120}; // Values of items
    vector<int> wt = {10, 20, 30}; // Weights of items
    int n = val.size(); // Number of items

    // Output the maximum value that can be obtained
    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
