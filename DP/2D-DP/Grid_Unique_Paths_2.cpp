#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: SPACE OPTIMIZED
// TC: O(M * N)
// SC: O(2N)
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1)
        return 0;

    vector<int> dp(n, 0);

    for (int row = 0; row < m; ++row)
    {
        vector<int> curr(n, 0);

        for (int col = 0; col < n; ++col)
        {
            if (row == 0 && col == 0)
                curr[col] = 1;
            else if (obstacleGrid[row][col] == 1)
                curr[col] = 0;
            else
            {
                int left = 0, up = 0;

                if (col > 0)
                    left = curr[col - 1];
                if (row > 0)
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
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1)
        return 0;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    dp[0][0] = 1;

    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            if (row == 0 && col == 0)
                continue;

            int left = 0, up = 0;

            if (obstacleGrid[row][col] == 1)
                dp[row][col] = 0;
            else
            {
                if (col > 0)
                    left = dp[row][col - 1];
                if (row > 0)
                    up = dp[row - 1][col];

                dp[row][col] = left + up;
            }
        }
    }

    return dp[m - 1][n - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(M * N)
// SC: O(PATHS) = O(M - 1 + N - 1) + O(m * n)
int findPaths(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;

    if (row < 0 || col < 0)
        return 0;

    if (mat[row][col] == 1)
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = findPaths(row, col - 1, mat, dp);
    int up = findPaths(row - 1, col, mat, dp);

    return dp[row][col] = left + up;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1)
        return 0;

    vector<vector<int>> dp(m, vector<int>(n, -1));

    return findPaths(m - 1, n - 1, obstacleGrid, dp);
}

// APPROACH 1: RECURSION
// TC: O(2*(M * N))
// SC: O(PATHS) = O(M - 1 + N - 1)
#include <bits/stdc++.h>

int findPaths(int row, int col, vector<vector<int>> &mat)
{
    if (row == 0 && col == 0)
        return 1;

    if (row < 0 || col < 0)
        return 0;

    if (mat[row][col] == 1)
        return 0;

    int left = findPaths(row, col - 1, mat);
    int up = findPaths(row - 1, col, mat);

    return left + up;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1)
        return 0;

    return findPaths(m - 1, n - 1, obstacleGrid);
}