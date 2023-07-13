#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: SPACE OPTIMIZED, OPTIMAL
// TC: O(M * N)
// SC: O(2N)
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<int> dp(m, 0);

    for (int row = 0; row < n; ++row)
    {
        vector<int> curr(m, 0);

        for (int col = 0; col < m; ++col)
        {
            if (row == 0 && col == 0)
                curr[col] = grid[row][col];

            else
            {
                int up = 1e9, left = 1e9;

                if (row > 0)
                    up = grid[row][col] + dp[col];
                if (col > 0)
                    left = grid[row][col] + curr[col - 1];

                curr[col] = min(up, left);
            }
        }

        dp = curr;
    }

    return dp[m - 1];
}

// APPROACH 3: DP, TABULATION
// TC: O(M * N)
// SC: O(M * N)
int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (row == 0 && col == 0)
                dp[row][col] = grid[row][col];

            else
            {
                int up = 1e9, left = 1e9;

                if (row > 0)
                    up = grid[row][col] + dp[row - 1][col];
                if (col > 0)
                    left = grid[row][col] + dp[row][col - 1];

                dp[row][col] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(M * N)
// SC: O(PATHS) = O(M - 1 + N - 1) + O(m * n)
int findMinPath(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return grid[0][0];

    if (row < 0 || col < 0)
        return 1e9;

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = grid[row][col] + findMinPath(row - 1, col, grid, dp);
    int left = grid[row][col] + findMinPath(row, col - 1, grid, dp);

    return dp[row][col] = min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return findMinPath(n - 1, m - 1, grid, dp);
}

// APPROACH 1: RECURSION
// TC: O(2*(M * N))
// SC: O(PATHS) = O(M - 1 + N - 1)
int findMinPath(int row, int col, vector<vector<int>> &grid)
{
    if (row == 0 && col == 0)
        return grid[0][0];

    if (row < 0 || col < 0)
        return 1e9;

    int up = grid[row][col] + findMinPath(row - 1, col, grid);
    int left = grid[row][col] + findMinPath(row, col - 1, grid);

    return min(up, left);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();

    return findMinPath(n - 1, m - 1, grid);
}