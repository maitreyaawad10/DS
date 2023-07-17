#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(TARGET)
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(k + 1, 0), curr(k + 1, 0);

    dp[0] = curr[0] = 1;

    if (arr[0] <= k)
        dp[arr[0]] = 1;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 1; target <= k; ++target)
        {
            int notPick = dp[target];
            int pick = 0;

            if (arr[index] <= target)
                pick = dp[target - arr[index]];

            curr[target] = (pick + notPick) % mod;
        }

        dp = curr;
    }

    return (dp[k]);
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; ++i)
        dp[i][0] = 1;

    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 1; target <= k; ++target)
        {
            int notPick = dp[index - 1][target];
            int pick = 0;

            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];

            dp[index][target] = (pick + notPick) % mod;
        }
    }

    return (dp[n - 1][k]);
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * target)
// SC: O(N) + O(N * target)
int countSubsets(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (index == 0)
    {
        if (arr[0] == target)
            return 1;
        return 0;
    }

    if (dp[index][target] != -1)
        return dp[index][target];

    int notPick = countSubsets(index - 1, target, arr, dp);
    int pick = 0;
    if (arr[index] <= target)
        pick = countSubsets(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return countSubsets(index, k, arr, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N))
// SC: O(N)
int countSubsets(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return 1;

    if (index == 0)
    {
        if (arr[0] == target)
            return 1;
        return 0;
    }

    int notPick = countSubsets(index - 1, target, arr);
    int pick = 0;
    if (arr[index] <= target)
        pick = countSubsets(index - 1, target - arr[index], arr);

    return (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    int index = n - 1;

    return countSubsets(index, k, arr);
}