#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: OPTIMAL APPROACH
// TC: O(M - 1) OR O(N - 1)
// SC: O(1)
int uniquePaths(int m, int n)
{
    int N = m + n - 2;
    int r = m - 1;
    double res = 1;

    for (int i = 1; i <= r; ++i)
    {
        res = res * (N - r + i) / i;
    }

    return (int)res;
}

// APPROACH 4: SPACE OPTIMIZED
// TC: O(M * N)
// SC: O(2N)
int uniquePaths(int m, int n)
{
    vector<int> dp(n, 0);

    for (int row = 0; row < m; ++row)
    {
        vector<int> curr(n, 0);
        for (int col = 0; col < n; ++col)
        {
            if (row == 0 && col == 0)
                curr[col] = 1;
            else
            {
                int left = 0, up = 0;

                if (col - 1 >= 0)
                    left = curr[col - 1];
                if (row - 1 >= 0)
                    up = dp[col];

                curr[col] = left + up;
            }
        }
        dp = curr;
    }

    return dp[n - 1];
}

// APPROACH 3: DP, TABULATION
// TC: O(M * N)
// SC: O(M * N)
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (row == 0 && col == 0)
                continue;
            int left = 0, up = 0;

            if (col - 1 >= 0)
                left = dp[row][col - 1];
            if (row - 1 >= 0)
                up = dp[row - 1][col];

            dp[row][col] = left + up;
        }
    }

    return dp[m - 1][n - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(M * N)
// SC: O(PATHS) = O(M - 1 + N - 1) + O(m * n)
int findPaths(int row, int col, int m, int n, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;

    if (row < 0 || col < 0)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = findPaths(row, col - 1, m, n, dp);
    int up = findPaths(row - 1, col, m, n, dp);

    return dp[row][col] = left + up;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return findPaths(m - 1, n - 1, m, n, dp);
}

// APPROACH 1: RECURSION
// TC: O(2*(M * N))
// SC: O(PATHS) = O(M - 1 + N - 1)
#include <bits/stdc++.h>

int findPaths(int row, int col, int m, int n)
{
    if (row == 0 && col == 0)
        return 1;

    if (row < 0 || col < 0)
        return 0;

    int left = findPaths(row, col - 1, m, n);
    int up = findPaths(row - 1, col, m, n);

    return left + up;
}

int uniquePaths(int m, int n)
{
    return findPaths(m - 1, n - 1, m, n);
}