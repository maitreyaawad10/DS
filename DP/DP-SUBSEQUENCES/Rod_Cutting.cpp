#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: DP, ULTRA SPACE OPTIMIZATION
// TC: O(N * N)
// SC: O(N) - SINGLE ARRAY INSTEAD OF TWO ARRAYS
int cutRod(vector<int> &price, int n)
{
    vector<int> curr(n + 1, 0);

    for (int N = 0; N <= n; ++N)
        curr[N] = N * price[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currN = 0; currN <= n; ++currN)
        {
            int notPick = 0 + curr[currN];
            int pick = INT_MIN;

            int rodLength = index + 1;
            if (rodLength <= currN)
                pick = price[index] + curr[currN - rodLength];

            curr[currN] = max(pick, notPick);
        }
    }

    return curr[n];
}

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * N)
// SC: O(2 * N)
int cutRod(vector<int> &price, int n)
{
    vector<int> dp(n + 1, 0), curr(n + 1, 0);

    for (int N = 0; N <= n; ++N)
        dp[N] = N * price[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currN = 0; currN <= n; ++currN)
        {
            int notPick = 0 + dp[currN];
            int pick = INT_MIN;

            int rodLength = index + 1;
            if (rodLength <= currN)
                pick = price[index] + curr[currN - rodLength];

            curr[currN] = max(pick, notPick);
        }

        dp = curr;
    }

    return dp[n];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// SC: O(N * N)
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int N = 0; N <= n; ++N)
        dp[0][N] = N * price[0];

    for (int index = 1; index < n; ++index)
    {
        for (int currN = 0; currN <= n; ++currN)
        {
            int notPick = 0 + dp[index - 1][currN];
            int pick = INT_MIN;

            int rodLength = index + 1;
            if (rodLength <= currN)
                pick = price[index] + dp[index][currN - rodLength];

            dp[index][currN] = max(pick, notPick);
        }
    }

    return dp[n - 1][n];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N * N) + >> O(N)
int findMaxCost(int index, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
        return (n * price[index]);

    if (dp[index][n] != -1)
        return dp[index][n];

    int notPick = 0 + findMaxCost(index - 1, n, price, dp);
    int pick = INT_MIN;

    int rodLength = index + 1;
    if (rodLength <= n)
        pick = price[index] + findMaxCost(index, n - rodLength, price, dp);

    return dp[index][n] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    int index = n - 1;
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return findMaxCost(index, n, price, dp);
}

// APPROACH 1: RECURSION
// TC: >> O(2 ^ (N))
// SC: >> O(N)
int findMaxCost(int index, int n, vector<int> &price)
{
    if (index == 0)
        return (n * price[index]);

    int notPick = 0 + findMaxCost(index - 1, n, price);
    int pick = INT_MIN;

    int rodLength = index + 1;
    if (rodLength <= n)
        pick = price[index] + findMaxCost(index, n - rodLength, price);

    return max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    int index = n - 1;
    return findMaxCost(index, n, price);
}