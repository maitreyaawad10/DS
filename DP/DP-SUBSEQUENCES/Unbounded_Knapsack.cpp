#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: DP, ULTRA SPACE OPTIMIZATION
// TC: O(N * WEIGHT)
// SC: O(WEIGHT) - SINGLE ARRAY INSTEAD OF TWO ARRAYS
int unboundedKnapsack(int n, int W, vector<int> &pf, vector<int> &wt)
{
    vector<int> curr(W + 1, 0);

    for (int w = 0; w <= W; w++)
        curr[w] = ((w / wt[0]) * pf[0]);

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = 0; currWeight <= W; ++currWeight)
        {
            int notPickCurrItem = 0 + curr[currWeight];
            int pickCurrItem = INT_MIN;

            if (wt[index] <= currWeight)
                pickCurrItem = pf[index] + curr[currWeight - wt[index]];

            curr[currWeight] = max(pickCurrItem, notPickCurrItem);
        }
    }

    return curr[W];
}

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * WEIGHT)
// SC: O(2 * WEIGHT)
int unboundedKnapsack(int n, int W, vector<int> &pf, vector<int> &wt)
{
    vector<int> dp(W + 1, 0), curr(W + 1, 0);

    for (int w = 0; w <= W; w++)
        dp[w] = ((w / wt[0]) * pf[0]);

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = 0; currWeight <= W; ++currWeight)
        {
            int notPickCurrItem = 0 + dp[currWeight];
            int pickCurrItem = INT_MIN;

            if (wt[index] <= currWeight)
                pickCurrItem = pf[index] + curr[currWeight - wt[index]];

            curr[currWeight] = max(pickCurrItem, notPickCurrItem);
        }

        dp = curr;
    }

    return dp[W];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * WEIGHT)
// SC: O(N * WEIGHT)
int unboundedKnapsack(int n, int W, vector<int> &pf, vector<int> &wt)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    for (int w = 0; w <= W; w++)
        dp[0][w] = ((w / wt[0]) * pf[0]);

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = 0; currWeight <= W; ++currWeight)
        {
            int notPickCurrItem = 0 + dp[index - 1][currWeight];
            int pickCurrItem = INT_MIN;

            if (wt[index] <= currWeight)
                pickCurrItem = pf[index] + dp[index][currWeight - wt[index]];

            dp[index][currWeight] = max(pickCurrItem, notPickCurrItem);
        }
    }

    return dp[n - 1][W];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * WEIGHT)
// SC: O(N * WEIGHT) + >> O(N)
int findMaxProfit(int index, int W, vector<int> &pf, vector<int> &wt,
                  vector<vector<int>> &dp)
{
    if (index == 0)
        return (W / wt[0]) * pf[0];

    if (dp[index][W] != -1)
        return dp[index][W];

    int notPickCurrItem = 0 + findMaxProfit(index - 1, W, pf, wt, dp);
    int pickCurrItem = INT_MIN;

    if (wt[index] <= W)
        pickCurrItem = pf[index] + findMaxProfit(index, W - wt[index], pf, wt, dp);

    return dp[index][W] = max(pickCurrItem, notPickCurrItem);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return findMaxProfit(index, w, profit, weight, dp);
}

// APPROACH 1: RECURSION
// TC: >> O(2 ^ (N))
// SC: >> O(N)
int findMaxProfit(int index, int W, vector<int> &pf, vector<int> &wt)
{
    if (index == 0)
        return (W / wt[0]) * pf[0];

    int notPickCurrItem = 0 + findMaxProfit(index - 1, W, pf, wt);
    int pickCurrItem = INT_MIN;

    if (wt[index] <= W)
        pickCurrItem = pf[index] + findMaxProfit(index, W - wt[index], pf, wt);

    return max(pickCurrItem, notPickCurrItem);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    int index = n - 1;
    return findMaxProfit(index, w, profit, weight);
}