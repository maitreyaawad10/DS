#include <bits/stdc++.h>

using namespace std;

// SAME PROBLEM AS SUBSET SUM EQUAL TO TARGET, HERE TARGET WILL BE (SUM / 2)
// APPROACH 2: DP, SPACE OPTIMIZATION
// TC: O(N * target)
// SC: O(TARGET)
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;

    for (auto value : arr)
    {
        sum += value;
    }

    if (sum % 2 != 0)
        return false;

    int k = sum / 2;

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

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;

    for (auto value : arr)
    {
        sum += value;
    }

    if (sum % 2 != 0)
        return false;

    return f(n - 1, sum / 2, arr);
}