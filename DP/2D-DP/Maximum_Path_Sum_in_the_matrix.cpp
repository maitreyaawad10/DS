#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: SPACE OPTIMIZED, OPTIMAL
// TC: O(N * M)
// SC: O(2N)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    vector<int> dp(m, 0);

    for (int row = 0; row < n; ++row)
    {
        vector<int> curr(m, 0);

        for (int col = 0; col < m; ++col)
        {
            if (row == 0)
                curr[col] = matrix[row][col];
            else
            {
                int topLeft = -1e8, topRight = -1e9;
                int up = matrix[row][col] + dp[col];
                if (col - 1 >= 0)
                    topLeft = matrix[row][col] + dp[col - 1];
                if (col + 1 < m)
                    topRight = matrix[row][col] + dp[col + 1];

                curr[col] = max(up, max(topLeft, topRight));
            }
        }

        dp = curr;
    }

    int maxi = dp[0];
    for (int i = 0; i < m; ++i)
    {
        maxi = max(maxi, dp[i]);
    }

    return maxi;
}
// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (row == 0)
                dp[row][col] = matrix[row][col];
            else
            {
                int topLeft = -1e8, topRight = -1e9;
                int up = matrix[row][col] + dp[row - 1][col];
                if (col - 1 >= 0)
                    topLeft = matrix[row][col] + dp[row - 1][col - 1];
                if (col + 1 < m)
                    topRight = matrix[row][col] + dp[row - 1][col + 1];

                dp[row][col] = max(up, max(topLeft, topRight));
            }
        }
    }

    int maxi = dp[n - 1][0];
    for (int i = 0; i < m; ++i)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }

    return maxi;
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N) + O(N * M)
int findMinPath(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (col < 0 || col >= matrix[0].size())
        return -1e8;

    if (row == 0)
        return matrix[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int up = matrix[row][col] + findMinPath(row - 1, col, matrix, dp);
    int topLeft = matrix[row][col] + findMinPath(row - 1, col - 1, matrix, dp);
    int topRight = matrix[row][col] + findMinPath(row - 1, col + 1, matrix, dp);

    return dp[row][col] = max(up, max(topLeft, topRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e8;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < m; ++i)
    {
        int currAns = findMinPath(n - 1, i, matrix, dp);
        maxi = max(maxi, currAns);
    }

    return maxi;
}

// APPROACH 1: RECURSION
// TC: O(3*(N * N))
// SC: O(PATHS) = O(N) AS N WILL BE PATH LENGTH
#include <bits/stdc++.h>

int findMinPath(int row, int col, vector<vector<int>> &matrix)
{
    if (col < 0 || col >= matrix[0].size())
        return -1e8;

    if (row == 0)
        return matrix[row][col];

    int up = matrix[row][col] + findMinPath(row - 1, col, matrix);
    int topLeft = matrix[row][col] + findMinPath(row - 1, col - 1, matrix);
    int topRight = matrix[row][col] + findMinPath(row - 1, col + 1, matrix);

    return max(up, max(topLeft, topRight));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int maxi = -1e8;

    for (int i = 0; i < m; ++i)
    {
        int currAns = findMinPath(n - 1, i, matrix);
        maxi = max(maxi, currAns);
    }

    return maxi;
}