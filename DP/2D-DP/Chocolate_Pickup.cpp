#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(9*(N * M * M))
// SC: O(N * M * M)
int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; ++j1)
    {
        for (int j2 = 0; j2 < m; ++j2)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        for (int jAlice = 0; jAlice < m; ++jAlice)
        {
            for (int jBob = 0; jBob < m; ++jBob)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; ++dj1)
                {
                    for (int dj2 = -1; dj2 <= 1; ++dj2)
                    {
                        int currMax = 0;
                        if (jAlice == jBob) // if alice and bob are in the same cell
                            currMax = grid[i][jAlice];
                        else // if alice and bob are not in the same cell
                            currMax = grid[i][jAlice] + grid[i][jBob];

                        if (jAlice + dj1 < m && jAlice + dj1 >= 0 && jBob + dj2 < m && jBob + dj2 >= 0)
                            currMax += dp[i + 1][jAlice + dj1][jBob + dj2];
                        else
                            currMax = -1e8;

                        maxi = max(maxi, currMax);
                    }
                }

                dp[i][jAlice][jBob] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(9*(N * M * M))
// SC: O(N) + O(N * M * M)
int findMaxChocolates(int i, int jAlice, int jBob, int n, int m,
                      vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (jAlice < 0 || jAlice >= m || jBob < 0 || jBob >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (jAlice == jBob) // if alice and bob are in the same cell
            return grid[i][jAlice];
        else // if alice and bob are not in the same cell
            return grid[i][jAlice] + grid[i][jBob];
    }

    if (dp[i][jAlice][jBob] != -1)
        return dp[i][jAlice][jBob];

    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; ++dj1)
    {
        for (int dj2 = -1; dj2 <= 1; ++dj2)
        {
            int currMax = 0;
            if (jAlice == jBob)
            { // if alice and bob are in the same cell
                currMax = grid[i][jAlice] + findMaxChocolates(i + 1, jAlice + dj1, jBob + dj2, n, m, grid, dp);
            }
            else
            { // if alice and bob are not in the same cell
                currMax = grid[i][jAlice] + grid[i][jBob] + findMaxChocolates(i + 1, jAlice + dj1, jBob + dj2, n, m, grid, dp);
            }
            maxi = max(maxi, currMax);
        }
    }

    return dp[i][jAlice][jBob] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

    int aliceStart = 0, bobStart = c - 1, startRow = 0;
    return findMaxChocolates(startRow, aliceStart, bobStart, r, c, grid, dp);
}

// APPROACH 1: RECURSION
// TC: O(9*(3^(N * M)))
// SC: O(PATHS) = O(N)
int findMaxChocolates(int i, int jAlice, int jBob, int n, int m,
                      vector<vector<int>> &grid)
{
    if (jAlice < 0 || jAlice >= m || jBob < 0 || jBob >= m)
        return -1e8;

    if (i == n - 1)
    {
        if (jAlice == jBob) // if alice and bob are in the same cell
            return grid[i][jAlice];
        else // if alice and bob are not in the same cell
            return grid[i][jAlice] + grid[i][jBob];
    }

    int maxi = 0;
    for (int dj1 = -1; dj1 <= 1; ++dj1)
    {
        for (int dj2 = -1; dj2 <= 1; ++dj2)
        {
            int currMax = -1e8;
            if (jAlice == jBob)
            { // if alice and bob are in the same cell
                currMax = grid[i][jAlice] + findMaxChocolates(i + 1, jAlice + dj1, jBob + dj2, n, m, grid);
            }
            else
            { // if alice and bob are not in the same cell
                currMax = grid[i][jAlice] + grid[i][jBob] + findMaxChocolates(i + 1, jAlice + dj1, jBob + dj2, n, m, grid);
            }
            maxi = max(maxi, currMax);
        }
    }

    return maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    int aliceStart = 0, bobStart = c - 1, startRow = 0;
    return findMaxChocolates(startRow, aliceStart, bobStart, r, c, grid);
}