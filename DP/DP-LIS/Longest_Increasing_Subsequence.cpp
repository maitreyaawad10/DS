#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: OPTIMAL APPROACH, BINARY SEARCH (LOWER BOUND)
// TC: O(N * LOG (N))
// SC: O(N)
int lengthOfLIS(vector<int> &nums)
{
    vector<int> temp;
    temp.push_back(nums[0]);

    int length = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            length++;
        }
        else
        {
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[index] = nums[i];
        }
    }

    return length;
}

// APPROACH 4: DP, TABULATION, SPACE OPTIMIZATION
// TC: O(N * N)
// SC: O(N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 2, 0), curr(n + 2, 0);

    for (int lastIndex = 0; lastIndex <= n + 1; ++lastIndex)
        dp[lastIndex] = 0;

    for (int index = 1; index <= n; ++index)
    {
        for (int lastIndex = 1; lastIndex <= n + 1; ++lastIndex)
        {
            int notPick = 0 + dp[lastIndex];
            int pick = 0;

            if (lastIndex == nums.size() + 1 || nums[index - 1] < nums[lastIndex - 1])
                pick = 1 + dp[index];

            curr[lastIndex] = max(pick, notPick);
        }

        dp = curr;
    }

    return dp[n + 1];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// SC: O(N * N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

    for (int lastIndex = 0; lastIndex <= n + 1; ++lastIndex)
        dp[0][lastIndex] = 0;

    for (int index = 1; index <= n; ++index)
    {
        for (int lastIndex = 1; lastIndex <= n + 1; ++lastIndex)
        {
            int notPick = 0 + dp[index - 1][lastIndex];
            int pick = 0;

            if (lastIndex == nums.size() + 1 || nums[index - 1] < nums[lastIndex - 1])
                pick = 1 + dp[index - 1][index];

            dp[index][lastIndex] = max(pick, notPick);
        }
    }

    return dp[n][n + 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N * N) + O(N)
int findLIS(int index, int lastIndex, vector<int> &nums, vector<vector<int>> &dp)
{
    if (index == 0)
        return 0;

    if (dp[index][lastIndex] != -1)
        return dp[index][lastIndex];

    int notPick = 0 + findLIS(index - 1, lastIndex, nums, dp);
    int pick = 0;

    if (lastIndex == nums.size() + 1 || nums[index - 1] < nums[lastIndex - 1])
        pick = 1 + findLIS(index - 1, index, nums, dp);

    return dp[index][lastIndex] = max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int index = n;
    int lastIndex = n + 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));

    return findLIS(index, lastIndex, nums, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N)
// SC: O(N)
int findLIS(int index, int lastIndex, vector<int> &nums)
{
    if (index < 0)
        return 0;

    int notPick = 0 + findLIS(index - 1, lastIndex, nums);
    int pick = 0;

    if (lastIndex == nums.size() || nums[index] < nums[lastIndex])
        pick = 1 + findLIS(index - 1, index, nums);

    return max(pick, notPick);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int index = n - 1;
    int lastIndex = nums.size();

    return findLIS(index, lastIndex, nums);
}