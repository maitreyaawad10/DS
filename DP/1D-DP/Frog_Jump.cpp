#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: OPTIMAL, DP, (space optimized)
// TC: O(N)
// SC: O(1)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    int prev1 = 0, prev2 = 0;

    for (int i = 1; i < n; ++i)
    {
        int leftMinEnergy = prev1 + abs(heights[i] - heights[i - 1]);
        int rightMinEnergy = INT_MAX;

        if (i > 1)
            rightMinEnergy = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(leftMinEnergy, rightMinEnergy);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// APPROACH 1: RECURSION
// TC: 2^N
// SC: O(N)
int minEnergy(int n, vector<int> &heights)
{
    if (n == 0)
        return 0;

    int leftMinEnergy = minEnergy(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int rightMinEnergy = INT_MAX;

    if (n > 1)
    {
        rightMinEnergy = minEnergy(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    }

    return min(leftMinEnergy, rightMinEnergy);
}

int frogJump(int n, vector<int> &heights)
{
    return minEnergy(n - 1, heights);
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N)
// SC: O(N)
int minEnergy(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int leftMinEnergy = minEnergy(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int rightMinEnergy = INT_MAX;

    if (n > 1)
    {
        rightMinEnergy = minEnergy(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }

    return dp[n] = min(leftMinEnergy, rightMinEnergy);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return minEnergy(n - 1, heights, dp);
}

// APPROACH 3: DP, TABULATION
// TC: O(N)
// SC: O(N)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; ++i)
    {
        int leftMinEnergy = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int rightMinEnergy = INT_MAX;

        if (i > 1)
            rightMinEnergy = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(leftMinEnergy, rightMinEnergy);
    }

    return dp[n - 1];
}
