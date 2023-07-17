#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: DP, MORE SPACE OPTIMIZATION(SINGLE EXTRA ARRAY)
// TC: O(N * target)
// SC: O(TARGET)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> dp(maxWeight + 1, 0);

    for (int W = weight[0]; W <= maxWeight; ++W)
        dp[W] = value[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = maxWeight; currWeight >= 1; --currWeight)
        {
            int notPickCurrItem = 0 + dp[currWeight];
            int pickCurrItem = INT_MIN;

            if (weight[index] <= currWeight)
                pickCurrItem = value[index] + dp[currWeight - weight[index]];

            dp[currWeight] = max(pickCurrItem, notPickCurrItem);
        }
    }

    return dp[maxWeight];
}

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(2*TARGET)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> dp(maxWeight + 1, 0), curr(maxWeight + 1, 0);

    for (int W = weight[0]; W <= maxWeight; ++W)
        dp[W] = value[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = 1; currWeight <= maxWeight; ++currWeight)
        {
            int notPickCurrItem = 0 + dp[currWeight];
            int pickCurrItem = INT_MIN;

            if (weight[index] <= currWeight)
                pickCurrItem = value[index] + dp[currWeight - weight[index]];

            curr[currWeight] = max(pickCurrItem, notPickCurrItem);
        }

        dp = curr;
    }

    return dp[maxWeight];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int W = weight[0]; W <= maxWeight; ++W)
        dp[0][W] = value[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currWeight = 1; currWeight <= maxWeight; ++currWeight)
        {
            int notPickCurrItem = 0 + dp[index - 1][currWeight];
            int pickCurrItem = INT_MIN;

            if (weight[index] <= currWeight)
                pickCurrItem = value[index] + dp[index - 1][currWeight - weight[index]];

            dp[index][currWeight] = max(pickCurrItem, notPickCurrItem);
        }
    }

    return dp[n - 1][maxWeight];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * maxWeight)
// SC: O(N) + O(N * maxWeight)
int findMaxProfit(int index, vector<int> wt, vector<int> vl, int maxWeight,
                  vector<vector<int>> &dp)
{
    if (maxWeight == 0)
    {
        return 0;
    }

    if (index == 0)
    {
        if (wt[index] <= maxWeight)
            return vl[index];
        return 0;
    }

    if (dp[index][maxWeight] != -1)
        return dp[index][maxWeight];

    int notPickCurrItem = 0 + findMaxProfit(index - 1, wt, vl, maxWeight, dp);
    int pickCurrItem = INT_MIN;
    if (wt[index] <= maxWeight)
        pickCurrItem = vl[index] + findMaxProfit(index - 1, wt, vl, maxWeight - wt[index], dp);

    return dp[index][maxWeight] = max(pickCurrItem, notPickCurrItem);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return findMaxProfit(index, weight, value, maxWeight, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N))
// SC: O(N)
int findMaxProfit(int index, vector<int> wt, vector<int> vl, int maxWeight)
{
    if (maxWeight == 0)
    {
        return 0;
    }

    if (index == 0)
    {
        if (wt[index] <= maxWeight)
            return vl[index];
        return 0;
    }

    int notPickCurrItem = 0 + findMaxProfit(index - 1, wt, vl, maxWeight);
    int pickCurrItem = INT_MIN;
    if (wt[index] <= maxWeight)
        pickCurrItem = vl[index] + findMaxProfit(index - 1, wt, vl, maxWeight - wt[index]);

    return max(pickCurrItem, notPickCurrItem);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    int index = n - 1;
    return findMaxProfit(index, weight, value, maxWeight);
}