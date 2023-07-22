#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: TABULATION, SPACE OPTIMIZATION
// TC: O(N*2*3), SC: O(2*3) or O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;

    vector<vector<int>> dp(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for (int index = n - 1; index >= 0; --index)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= 2; ++cap)
            {
                if (buy == 1)
                {
                    int buy = -prices[index] + dp[0][cap];
                    int notBuy = 0 + dp[1][cap];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + dp[1][cap - 1];
                    int notSell = 0 + dp[0][cap];
                    profit = max(sell, notSell);
                }

                curr[buy][cap] = profit;
            }

            dp = curr;
        }
    }

    return dp[1][2];
}

// APPROACH 3: TABULATION
// TC: O(N*2*3), SC: O(N*2*3)
int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // if you use arrays instead of vectors only then these base cases are needed
    // for (int index = 0; index < n; ++index) {
    //     for (int buy = 0; buy <= 1; ++buy) {
    //         dp[index][buy][0] = 0;
    //     }
    // }

    // for (int buy = 0; buy <= 1; ++buy) {
    //     for (int cap = 0; cap <= 2; ++cap) {
    //         dp[n][buy][cap] = 0;
    //     }
    // }

    for (int index = n - 1; index >= 0; --index)
    {
        for (int buy = 0; buy <= 1; ++buy)
        {
            for (int cap = 1; cap <= 2; ++cap)
            {
                if (buy == 1)
                {
                    int buy = -prices[index] + dp[index + 1][0][cap];
                    int notBuy = 0 + dp[index + 1][1][cap];
                    profit = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1][cap - 1];
                    int notSell = 0 + dp[index + 1][0][cap];
                    profit = max(sell, notSell);
                }

                dp[index][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

// APPROACH 2: MEMOIZATION
// TC: O(N*2*3), SC: O(N*2*3) + O(N)
int findMaxProfit(int index, int buy, vector<int> &prices, int n, int &profit, int cap,
                  vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;

    if (index == n)
        return 0;

    if (dp[index][buy][cap] != -1)
        return dp[index][buy][cap];

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, prices, n, profit, cap, dp);
        int notBuy = 0 + findMaxProfit(index + 1, 1, prices, n, profit, cap, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, prices, n, profit, cap - 1, dp);
        int notSell = 0 + findMaxProfit(index + 1, 0, prices, n, profit, cap, dp);
        profit = max(sell, notSell);
    }

    return dp[index][buy][cap] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0, cap = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return findMaxProfit(0, 1, prices, n, profit, cap, dp);
}

// APPROACH 1: RECURSION
// TC: O(2^(N*2*3)), SC: O(N)
int findMaxProfit(int index, int buy, vector<int> &prices, int n, int &profit, int cap)
{
    if (cap == 0)
        return 0;

    if (index == n)
    {
        return 0;
    }

    if (buy == 1)
    {
        int buy = -prices[index] + findMaxProfit(index + 1, 0, prices, n, profit, cap);
        int notBuy = 0 + findMaxProfit(index + 1, 1, prices, n, profit, cap);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + findMaxProfit(index + 1, 1, prices, n, profit, cap - 1);
        int notSell = 0 + findMaxProfit(index + 1, 0, prices, n, profit, cap);
        profit = max(sell, notSell);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), profit = 0, cap = 2;
    return findMaxProfit(0, 1, prices, n, profit, cap);
}