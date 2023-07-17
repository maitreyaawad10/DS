#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(2 * TARGET)
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    int index = n - 1;
    vector<int> dp(x + 1, 0), curr(x + 1, 0);

    for (int T = 0; T <= x; ++T)
    {
        if (T % num[0] == 0)
            dp[T] = T / num[0];
        else
            dp[T] = 1e9;
    }

    for (index = 1; index < n; ++index)
    {
        for (int currT = 1; currT <= x; ++currT)
        {
            int notPickCurrItem = 0 + dp[currT];
            int pickCurrItem = 1e9;

            if (num[index] <= currT)
                pickCurrItem = 1 + curr[currT - num[index]];

            curr[currT] = min(pickCurrItem, notPickCurrItem);
        }

        dp = curr;
    }

    if (dp[x] == 1e9)
        return -1;
    return dp[x];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    for (int T = 0; T <= x; ++T)
    {
        if (T % num[0] == 0)
            dp[0][T] = T / num[0];
        else
            dp[0][T] = 1e9;
    }

    for (index = 1; index < n; ++index)
    {
        for (int currT = 1; currT <= x; ++currT)
        {
            int notPickCurrItem = 0 + dp[index - 1][currT];
            int pickCurrItem = 1e9;

            if (num[index] <= currT)
                pickCurrItem = 1 + dp[index][currT - num[index]];

            dp[index][currT] = min(pickCurrItem, notPickCurrItem);
        }
    }

    if (dp[n - 1][x] == 1e9)
        return -1;
    return dp[n - 1][x];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * TARGET)
// SC: O(N * TARGET) + >> O(N)
int findMinCoins(int index, vector<int> &coins, int x, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (x % coins[0] == 0)
            return (x / coins[0]);
        return 1e9;
    }

    if (dp[index][x] != -1)
        return dp[index][x];

    int notPickCurrItem = 0 + findMinCoins(index - 1, coins, x, dp);
    int pickCurrItem = 1e9;
    if (coins[index] <= x)
        pickCurrItem = 1 + findMinCoins(index, coins, x - coins[index], dp);

    return dp[index][x] = min(pickCurrItem, notPickCurrItem);
}

int coinChange(vector<int> &coins, int x)
{
    int n = coins.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    int ans = findMinCoins(index, coins, x, dp);

    if (ans == 1e9)
        return -1;

    return ans;
}

// APPROACH 1: RECURSION
// TC: >> O(2 ^ (N))
// SC: >> O(N)
int findMinCoins(int index, vector<int> &coins, int x)
{
    if (index == 0)
    {
        if (x % coins[0] == 0)
            return (x / coins[0]);
        return 1e9;
    }

    int notPickCurrItem = 0 + findMinCoins(index - 1, coins, x);
    int pickCurrItem = 1e9;
    if (coins[index] <= x)
        pickCurrItem = 1 + findMinCoins(index, coins, x - coins[index]);

    return min(pickCurrItem, notPickCurrItem);
}

int coinChange(vector<int> &coins, int x)
{
    int n = coins.size();
    int index = n - 1;
    int ans = findMinCoins(index, coins, x);

    if (ans == 1e9)
        return -1;

    return ans;
}