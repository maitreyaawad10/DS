#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O((N * N) * N)
// SC: O(N * N)
int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int start = n; start >= 1; --start)
    {
        for (int end = start; end <= n; ++end)
        {
            int maxCoins = INT_MIN;

            for (int index = start; index <= end; ++index)
            {
                int currCoins = (nums[start - 1] * nums[index] * nums[end + 1]) +
                                dp[start][index - 1] + dp[index + 1][end];

                maxCoins = max(maxCoins, currCoins);
            }

            dp[start][end] = maxCoins;
        }
    }

    return dp[1][n];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O((N * N) * N)
// SC: O(N * N) + O(N)
int findMaxCoins(int start, int end, vector<int> &nums, vector<vector<int>> &dp)
{
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int maxCoins = INT_MIN;
    for (int index = start; index <= end; ++index)
    {
        int currCoins = (nums[start - 1] * nums[index] * nums[end + 1]) +
                        findMaxCoins(start, index - 1, nums, dp) + findMaxCoins(index + 1, end, nums, dp);

        maxCoins = max(maxCoins, currCoins);
    }

    return dp[start][end] = maxCoins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return findMaxCoins(1, n, nums, dp);
}

// APPROACH 1: RECURSION
// TC: O(2^(N * N) * N)
// SC: O(N)
int findMaxCoins(int start, int end, vector<int> &nums)
{
    if (start > end)
        return 0;

    int maxCoins = INT_MIN;
    for (int index = start; index <= end; ++index)
    {
        int currCoins = (nums[start - 1] * nums[index] * nums[end + 1]) +
                        findMaxCoins(start, index - 1, nums) + findMaxCoins(index + 1, end, nums);

        maxCoins = max(maxCoins, currCoins);
    }

    return maxCoins;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return findMaxCoins(1, n, nums);
}