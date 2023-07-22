#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: TABULATION, SPACE OPTIMIZATION
// TC: O(N), SC: O(1)
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size(), profit = 0;

    vector<int> dp(2, 0);
    vector<int> curr(2, 0);

    for (int index = n - 1; index >= 0; --index)
    {
        int buy = -prices[index] + dp[0];
        int notBuy = 0 + dp[1];
        curr[1] = max(buy, notBuy);

        int sell = prices[index] + dp[1] - fee;
        int notSell = 0 + dp[0];
        curr[0] = max(sell, notSell);

        dp = curr;
    }

    return dp[1];
}

// APPROACH 3: TABULATION
// TC: O(N), SC: O(N*2)
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size(), profit = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        int buy = -prices[index] + dp[index + 1][0];
        int notBuy = 0 + dp[index + 1][1];
        dp[index][1] = max(buy, notBuy);

        int sell = prices[index] + dp[index + 1][1] - fee;
        int notSell = 0 + dp[index + 1][0];
        dp[index][0] = max(sell, notSell);
    }

    return dp[0][1];
}

// APPROACH 2: MEMOIZATION
// TC: N*2, SC: O(N*2) + O(N)
int findMaxProfit(int index, int buy, int fee, vector<int> &prices, int n, int &profit,
                  vector<vector<int>> &dp)
{
    if (index == n)
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, fee, prices, n, profit, dp);
        int notBuy = 0 + findMaxProfit(index + 1, 1, fee, prices, n, profit, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, fee, prices, n, profit, dp) - fee;
        int notSell = 0 + findMaxProfit(index + 1, 0, fee, prices, n, profit, dp);
        profit = max(sell, notSell);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size(), profit = 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return findMaxProfit(0, 1, fee, prices, n, profit, dp);
}

// APPROACH 1: RECURSION
// TC: 2^(N*2), SC: O(N)
int findMaxProfit(int index, int buy, int fee, vector<int> &prices, int n, int &profit)
{
    if (index == n)
    {
        return 0;
    }

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, fee, prices, n, profit);
        int notBuy = 0 + findMaxProfit(index + 1, 1, fee, prices, n, profit);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, fee, prices, n, profit) - fee;
        int notSell = 0 + findMaxProfit(index + 1, 0, fee, prices, n, profit);
        profit = max(sell, notSell);
    }

    return profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size(), profit = 0;
    return findMaxProfit(0, 1, fee, prices, n, profit);
}