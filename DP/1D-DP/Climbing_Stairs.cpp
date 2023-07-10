#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: OPTIMAL, DP, TABULATION (space optimized)
// TC: O(N)
// SC: O(1)
int climbStairs(int n)
{
    int prev1 = 1, prev2 = 1;

    for (int i = 2; i <= n; ++i)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// APPROACH 1: RECURSION
// TC: 2^N
// SC: O(N)
int findWays(int n)
{
    if (n == 1 || n == 0)
        return 1;

    return findWays(n - 1) + findWays(n - 2);
}

int climbStairs(int n)
{
    return findWays(n);
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N)
// SC: O(N)
int findWays(vector<int> &dp, int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = findWays(dp, n - 1) + findWays(dp, n - 2);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);

    return findWays(dp, n);
}

// APPROACH 3: DP, TABULATION
// TC: O(N)
// SC: O(N)
int climbStairs(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
