#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: SPACE OPTIMIZED, OPTIMAL
// TC: O(N * N)
// SC: O(2N)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<int> dp(n, 0);

    for (int lastRow = n - 1; lastRow >= 0; --lastRow)
        dp[lastRow] = triangle[n - 1][lastRow];

    for (int row = n - 2; row >= 0; --row)
    {
        vector<int> curr(n, 0);

        for (int col = row; col >= 0; --col)
        {
            int down = triangle[row][col] + dp[col];
            int downRight = triangle[row][col] + dp[col + 1];

            curr[col] = min(down, downRight);
        }

        dp = curr;
    }

    return dp[0];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// SC: O(N * N)
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int lastRow = n - 1; lastRow >= 0; --lastRow)
        dp[n - 1][lastRow] = triangle[n - 1][lastRow];

    for (int row = n - 2; row >= 0; --row)
    {
        for (int col = row; col >= 0; --col)
        {
            int down = triangle[row][col] + dp[row + 1][col];
            int downRight = triangle[row][col] + dp[row + 1][col + 1];

            dp[row][col] = min(down, downRight);
        }
    }

    return dp[0][0];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N) + O(N * N)
int findMinPath(int row, int col, vector<vector<int>> &triangle, int n, vector<vector<int>> dp)
{
    if (row == n - 1)
        return triangle[row][col];

    if (dp[row][col] != -1)
        return dp[row][col];

    int down = triangle[row][col] + findMinPath(row + 1, col, triangle, n, dp);
    int downRight = triangle[row][col] + findMinPath(row + 1, col + 1, triangle, n, dp);

    return dp[row][col] = min(down, downRight);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return findMinPath(0, 0, triangle, n, dp);
}

// APPROACH 1: RECURSION
// TC: O(2*(N * N))
// SC: O(PATHS) = O(N) AS N WILL BE PATH LENGTH
#include <bits/stdc++.h>

int findMinPath(int row, int col, vector<vector<int>> &triangle, int n)
{
    if (row == n - 1)
        return triangle[row][col];

    int down = triangle[row][col] + findMinPath(row + 1, col, triangle, n);
    int downRight = triangle[row][col] + findMinPath(row + 1, col + 1, triangle, n);

    return min(down, downRight);
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    return findMinPath(0, 0, triangle, n);
}