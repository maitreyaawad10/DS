#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// TC: O(N)
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    dp[n] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        int maxSum = 0, maxi = 0;

        for (int j = index; j < min(n, index + k); ++j)
        {
            maxi = max(maxi, arr[j]);
            int currSum = (maxi * (j - index + 1)) + dp[j + 1];
            maxSum = max(maxSum, currSum);
        }

        dp[index] = maxSum;
    }

    return dp[0];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N) + O(N)
int findMaxSum(int index, int n, vector<int> &arr, int k, vector<int> &dp)
{
    if (index == n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int maxSum = 0, maxi = 0;

    for (int j = index; j < min(n, index + k); ++j)
    {
        maxi = max(maxi, arr[j]);
        int currSum = (maxi * (j - index + 1)) + findMaxSum(j + 1, n, arr, k, dp);
        maxSum = max(maxSum, currSum);
    }

    return dp[index] = maxSum;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);

    return findMaxSum(0, n, arr, k, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N * N))
// SC: O(N)
int findMaxSum(int index, int n, vector<int> &arr, int k)
{
    if (index == n)
        return 0;

    int maxSum = 0, maxi = 0;

    for (int j = index; j < min(n, index + k); ++j)
    {
        maxi = max(maxi, arr[j]);
        int currSum = (maxi * (j - index + 1)) + findMaxSum(j + 1, n, arr, k);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    return findMaxSum(0, n, arr, k);
}