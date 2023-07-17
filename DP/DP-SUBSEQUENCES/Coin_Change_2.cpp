#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(2 * TARGET)
int change(int target, vector<int> &coins)
{
    int n = coins.size();
    vector<int> dp(target + 1, 0), curr(target + 1, 0);

    for (int T = 0; T <= target; ++T)
    {
        if (T % coins[0] == 0)
            dp[T] = 1;
    }

    for (int index = 1; index < n; ++index)
    {
        for (int currTarget = 0; currTarget <= target; ++currTarget)
        {
            int notPickCurrCoin = dp[currTarget];
            int pickCurrCoin = 0;

            if (coins[index] <= currTarget)
                pickCurrCoin = curr[currTarget - coins[index]];

            curr[currTarget] = pickCurrCoin + notPickCurrCoin;
        }

        dp = curr;
    }

    return dp[target];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int change(int target, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int T = 0; T <= target; ++T)
    {
        if (T % coins[0] == 0)
            dp[0][T] = 1;
    }

    for (int index = 1; index < n; ++index)
    {
        for (int currTarget = 0; currTarget <= target; ++currTarget)
        {
            int notPickCurrCoin = dp[index - 1][currTarget];
            int pickCurrCoin = 0;

            if (coins[index] <= currTarget)
                pickCurrCoin = dp[index][currTarget - coins[index]];

            dp[index][currTarget] = pickCurrCoin + notPickCurrCoin;
        }
    }

    return dp[n - 1][target];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * TARGET)
// SC: O(N * TARGET) + >> O(N)
int findWays(int index, vector<int> &coins, int x, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (x % coins[0] == 0)
            return 1;

        return 0;
    }

    if (dp[index][x] != -1)
        return dp[index][x];

    int notPickCurrItem = findWays(index - 1, coins, x, dp);
    int pickCurrItem = 0;

    if (coins[index] <= x)
        pickCurrItem = findWays(index, coins, x - coins[index], dp);

    return dp[index][x] = pickCurrItem + notPickCurrItem;
}

int change(int value, vector<int> &coins)
{
    int n = coins.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(value + 1, -1));
    return findWays(index, coins, value, dp);
}

// APPROACH 1: RECURSION
// TC: >> O(2 ^ (N))
// SC: >> O(N)
int findWays(int index, vector<int> &coins, int x)
{
    if (index == 0)
    {
        if (x % coins[0] == 0)
            return 1;

        return 0;
    }

    int notPickCurrItem = findWays(index - 1, coins, x);
    int pickCurrItem = 0;

    if (coins[index] <= x)
        pickCurrItem = findWays(index, coins, x - coins[index]);

    return pickCurrItem + notPickCurrItem;
}

int change(int value, vector<int> &coins)
{
    int n = coins.size();
    int index = n - 1;
    return findWays(index, coins, value);
}