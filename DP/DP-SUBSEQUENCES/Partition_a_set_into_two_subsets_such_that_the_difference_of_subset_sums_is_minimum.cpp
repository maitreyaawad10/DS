#include <bits/stdc++.h>

using namespace std;

// APPROACH 1: DP, TABULATION
// TC: O(N * target)
// SC: O(N * target)
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (auto value : arr)
        totSum += value;

    int k = totSum;
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

    int ans = 1e9;
    for (int i = 0; i <= k / 2; ++i)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = k - s1;
            ans = min(ans, abs(s1 - s2));
        }
    }

    return ans;
}
