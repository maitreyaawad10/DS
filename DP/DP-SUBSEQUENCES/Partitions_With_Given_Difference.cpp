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

    if (arr[0] == 0)
        dp[0] = 2;
    else
        dp[0] = 1;

    if (arr[0] != 0 && arr[0] <= k)
        dp[arr[0]] = 1;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 0; target <= k; ++target)
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;

    for (auto value : arr)
        totSum += value;

    if ((totSum - d < 0) || ((totSum - d) % 2))
        return 0;

    return findWays(arr, (totSum - d) / 2);
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 0; target <= k; ++target)
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;

    for (auto value : arr)
        totSum += value;

    if ((totSum - d < 0) || ((totSum - d) % 2))
        return 0;

    return findWays(arr, (totSum - d) / 2);
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * target)
// SC: O(N) + O(N * target)
int countSubsets(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;

    for (auto value : arr)
        totSum += value;

    if ((totSum - d < 0) || ((totSum - d) % 2))
        return 0;

    return findWays(arr, (totSum - d) / 2);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N))
// SC: O(N)
int countSubsets(int index, int target, vector<int> &arr)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
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

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;

    for (auto value : arr)
        totSum += value;

    if ((totSum - d < 0) || ((totSum - d) % 2))
        return 0;

    return findWays(arr, (totSum - d) / 2);
}