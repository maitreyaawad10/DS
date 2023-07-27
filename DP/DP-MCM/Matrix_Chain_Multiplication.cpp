#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O((N * N) * N)
// SC: O(N * N)
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i)
        dp[i][i] = 0;

    for (int start = N - 1; start >= 0; --start)
    {
        for (int end = start + 1; end < N; ++end)
        {
            int minSteps = 1e9;

            for (int k = start; k < end; ++k)
            {
                int steps = (arr[start - 1] * arr[k] * arr[end]) + dp[start][k] +
                            dp[k + 1][end];
                minSteps = min(minSteps, steps);
            }

            dp[start][end] = minSteps;
        }
    }

    return dp[1][N - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O((N * N) * N)
// SC: O(N * N) + O(N)
int findMinSteps(int start, int end, vector<int> &arr, vector<vector<int>> &dp)
{
    if (start == end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int minSteps = 1e9;
    for (int k = start; k < end; ++k)
    {
        int steps = (arr[start - 1] * arr[k] * arr[end]) + findMinSteps(start, k, arr, dp) +
                    findMinSteps(k + 1, end, arr, dp);
        minSteps = min(minSteps, steps);
    }

    return dp[start][end] = minSteps;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return findMinSteps(1, N - 1, arr, dp);
}

// APPROACH 1: RECURSION
// TC: O(2^(N * N) * N)
// SC: O(N)
int findMinSteps(int start, int end, vector<int> &arr)
{
    if (start == end)
        return 0;

    int minSteps = 1e9;
    for (int k = start; k < end; ++k)
    {
        int steps = (arr[start - 1] * arr[k] * arr[end]) + findMinSteps(start, k, arr) +
                    findMinSteps(k + 1, end, arr);
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return findMinSteps(1, N - 1, arr);
}