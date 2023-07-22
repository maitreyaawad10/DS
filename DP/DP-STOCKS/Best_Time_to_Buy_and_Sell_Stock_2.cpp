#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, GREEDY
// TC: O(N), SC: O(1)
int maxProfit(vector<int> &prices)
{
    int profit = 0, currMin = 1e9, n = prices.size();

    for (int i = 0; i < n; ++i)
    {
        currMin = min(currMin, prices[i]);

        if (prices[i] > currMin)
        {
            profit += (prices[i] - currMin);
            currMin = prices[i];
        }
    }

    return profit;
}

// APPROACH 4: TABULATION, SPACE OPTIMIZATION
// TC: N*2, SC: O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    vector<int> dp(2, 0), curr(2, 0);

    dp[0] = dp[1] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            if (buy == 1)
            {
                int buy = -prices[index] + dp[0];
                int notBuy = 0 + dp[1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + dp[1];
                int notSell = 0 + dp[0];
                profit = max(sell, notSell);
            }

            curr[buy] = profit;
        }

        dp = curr;
    }

    return dp[1];
}

// APPROACH 3: TABULATION
// TC: N*2, SC: O(N*2)
/*
without using inner for loop for buy, simply since it has 2 states 1 & 0, it dp[ind][1] & dp[ind][0]
int maxProfit(vector<int>& prices) {
    int n = prices.size(), profit = 0;
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        int buy = -prices[index] + dp[index + 1][0];
        int notBuy = 0 + dp[index + 1][1];
        dp[index][1] = max(buy, notBuy);

        int sell = prices[index] + dp[index + 2][1];
        int notSell = 0 + dp[index + 1][0];
        dp[index][0] = max(sell, notSell);
    }

    return dp[0][1];
}
*/

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = dp[n][1] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        for (int buy = 0; buy <= 1; ++buy) // this loop will only run twice and thus can be eliminated
        {
            if (buy == 1)
            {
                int buy = -prices[index] + dp[index + 1][0];
                int notBuy = 0 + dp[index + 1][1];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][1];
                int notSell = 0 + dp[index + 1][0];
                profit = max(sell, notSell);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}

// APPROACH 2: MEMOIZATION
// TC: N*2, SC: O(N*2) + O(N)
int findMaxProfit(int index, int buy, vector<int> &prices, int n, int &profit,
                  vector<vector<int>> &dp)
{
    if (index == n)
        return 0;

    if (dp[index][buy] != -1)
        return dp[index][buy];

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, prices, n, profit, dp);
        int notBuy = 0 + findMaxProfit(index + 1, 1, prices, n, profit, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, prices, n, profit, dp);
        int notSell = 0 + findMaxProfit(index + 1, 0, prices, n, profit, dp);
        profit = max(sell, notSell);
    }

    return dp[index][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return findMaxProfit(0, 1, prices, n, profit, dp);
}

// APPROACH 1: RECURSION
// TC: 2^(N*2), SC: O(N)
int findMaxProfit(int index, int buy, vector<int> &prices, int n, int &profit)
{
    if (index == n)
    {
        return 0;
    }

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, prices, n, profit);
        int notBuy = 0 + findMaxProfit(index + 1, 1, prices, n, profit);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, prices, n, profit);
        int notSell = 0 + findMaxProfit(index + 1, 0, prices, n, profit);
        profit = max(sell, notSell);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    return findMaxProfit(0, 1, prices, n, profit);
}