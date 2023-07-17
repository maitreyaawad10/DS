#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int targetSum(int n, int target, vector<int> &arr)
{
    vector<unordered_map<int, int>> dp(n);

    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][arr[0]] = 1;
        dp[0][-arr[0]] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (auto &value : dp[i - 1])
        {
            int curr = value.first;

            int positive = curr + arr[i];
            int negative = curr - arr[i];

            dp[i][positive] += value.second;
            dp[i][negative] += value.second;
        }
    }
    return dp[n - 1][target];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * TARGET)
// SC: O(N * TARGET) + O(N)
int findWays(int index, int target, vector<int> &arr, vector<unordered_map<int, int>> &dp)
{
    if (index == 0)
    {
        if ((arr[0] == 0) && (target == 0))
            return 2;

        if ((target + arr[0] == 0) || (target - arr[0] == 0))
            return 1;

        return 0;
    }

    if (dp[index].find(target) != dp[index].end())
        return dp[index][target];

    int positive = findWays(index - 1, target + arr[index], arr, dp);
    int negative = findWays(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = positive + negative;
}

int targetSum(int n, int target, vector<int> &arr)
{
    vector<unordered_map<int, int>> dp(n);
    return findWays(n - 1, target, arr, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N))
// SC: O(N)
int findWays(int index, int target, vector<int> &arr)
{
    if (index == 0)
    {
        if ((target == 0) && (arr[0] == 0))
            return 2;

        if ((target + arr[0] == 0) || (target - arr[0] == 0))
            return 1;

        return 0;
    }

    int positive = findWays(index - 1, target + arr[index], arr);
    int negative = findWays(index - 1, target - arr[index], arr);

    return positive + negative;
}

int targetSum(int n, int target, vector<int> &arr)
{
    return findWays(n - 1, target, arr);
}