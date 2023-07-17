#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(TARGET)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> dp(k + 1, 0), curr(k + 1, 0);

    dp[0] = curr[0] = true;
    if (arr[0] <= k)
        dp[arr[0]] = true;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 1; target <= k; ++target)
        {
            bool notPick = dp[target];
            bool pick = false;

            if (arr[index] <= target)
                pick = dp[target - arr[index]];

            curr[target] = pick || notPick;
        }
        dp = curr;
    }

    return dp[k];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int index = 1; index < n; ++index)
    {
        for (int target = 1; target <= k; ++target)
        {
            bool notPick = dp[index - 1][target];
            bool pick = false;

            if (arr[index] <= target)
                pick = dp[index - 1][target - arr[index]];

            dp[index][target] = pick || notPick;
        }
    }

    return dp[n - 1][k];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * target)
// SC: O(N) + O(N * target)
bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (index == 0)
        return (arr[0] == target);

    if (dp[index][target] != -1)
        return dp[index][target];

    bool notPick = f(index - 1, target, arr, dp);
    bool pick = false;
    if (arr[index] <= target)
        pick = f(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    int index = n - 1;
    return f(index, k, arr, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N))
// SC: O(N)
bool f(int index, int target, vector<int> &arr)
{
    if (target == 0)
        return true;

    if (index == 0)
        return (arr[0] == target);

    bool notPick = f(index - 1, target, arr);
    bool pick = false;
    if (arr[index] <= target)
        pick = f(index - 1, target - arr[index], arr);

    return pick || notPick;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    int index = n - 1;
    return f(index, k, arr);
}