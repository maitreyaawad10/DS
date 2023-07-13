#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: OPTIMAL, DP, (space optimized)
// TC: O(N)
// SC: O(1)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    int prev1 = nums[0], prev2 = nums[0];

    for (int i = 1; i < n; ++i)
    {
        int pickCurrElement = nums[i];

        if (i > 1)
            pickCurrElement += prev2;

        int notPickCurrElement = 0 + prev1;

        int curr = max(pickCurrElement, notPickCurrElement);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// APPROACH 1: RECURSION
// TC: 2^N
// SC: O(N)
int maxSum(int index, vector<int> &nums)
{
    if (index == 0)
        return nums[index];

    if (index < 0)
        return 0;

    int pickCurrElement = nums[index] + maxSum(index - 2, nums);
    int notPickCurrElement = 0 + maxSum(index - 1, nums);

    return max(pickCurrElement, notPickCurrElement);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    return maxSum(n - 1, nums);
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N)
// SC: O(N) + O(N)
int maxSum(int index, vector<int> &nums, vector<int> &dp)
{
    if (index == 0)
        return nums[index];

    if (index < 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int pickCurrElement = nums[index] + maxSum(index - 2, nums, dp);
    int notPickCurrElement = 0 + maxSum(index - 1, nums, dp);

    return dp[index] = max(pickCurrElement, notPickCurrElement);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    return maxSum(n - 1, nums, dp);
}

// APPROACH 3: DP, TABULATION
// TC: O(N)
// SC: O(N)
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];

    for (int i = 1; i < n; ++i)
    {
        int pickCurrElement = nums[i];

        if (i > 1)
            pickCurrElement += dp[i - 2];

        int notPickCurrElement = 0 + dp[i - 1];

        dp[i] = max(pickCurrElement, notPickCurrElement);
    }

    return dp[n - 1];
}
