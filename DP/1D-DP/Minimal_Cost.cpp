#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION, OPTIMAL
// TC: O(N * K)
// SC: O(N)
int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int index = 1; index < n; ++index)
    {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; ++j)
        {
            if (index - j >= 0)
            {
                int currMinJump = dp[index - j] + abs(height[index] - height[index - j]);
                minCost = min(minCost, currMinJump);
            }
            else
            {
                break;
            }
            dp[index] = minCost;
        }
    }

    return dp[n - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * K)
// SC: O(N) + O(N)
int minCost(int index, vector<int> &heights, int k, vector<int> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int ans = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
        if (index - j >= 0)
        {
            int currMinJump = minCost(index - j, heights, k, dp) + abs(heights[index] - heights[index - j]);
            ans = min(ans, currMinJump);
        }
        else
        {
            break;
        }
    }

    dp[index] = ans;
    return dp[index];
}

int minimizeCost(int n, int k, vector<int> &height)
{
    vector<int> dp(n, -1);
    return minCost(n - 1, height, k, dp);
}

// APPROACH 1: RECURSION
// TC: O(2^N * K)
// SC: O(N)