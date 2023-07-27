#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O((N * N) * N)
// SC: O(N * N)
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int start = c; start >= 1; --start)
    {
        for (int end = start; end <= c; ++end)
        {
            int minCuts = INT_MAX;

            for (int index = start; index <= end; ++index)
            {
                int currCuts = (cuts[end + 1] - cuts[start - 1]) + dp[start][index - 1] +
                               dp[index + 1][end];

                minCuts = min(minCuts, currCuts);
            }

            dp[start][end] = minCuts;
        }
    }

    return dp[1][c];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O((N * N) * N)
// SC: O(N * N) + O(N)
int findMinCost(int start, int end, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int minCuts = INT_MAX;

    for (int index = start; index <= end; ++index)
    {
        int currCuts = (cuts[end + 1] - cuts[start - 1]) + findMinCost(start, index - 1, cuts, dp) +
                       findMinCost(index + 1, end, cuts, dp);
        minCuts = min(minCuts, currCuts);
    }

    return dp[start][end] = minCuts;
}

int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    return findMinCost(1, c, cuts, dp);
}

// APPROACH 1: RECURSION
// TC: O(2^(N * N) * N)
// SC: O(N)
int findMinCost(int start, int end, vector<int> &cuts)
{
    if (start > end)
        return 0;

    int minCuts = INT_MAX;

    for (int index = start; index <= end; ++index)
    {
        int currCuts = (cuts[end + 1] - cuts[start - 1]) + findMinCost(start, index - 1, cuts) +
                       findMinCost(index + 1, end, cuts);
        minCuts = min(minCuts, currCuts);
    }

    return minCuts;
}

int cost(int n, vector<int> &cuts)
{
    int c = cuts.size();

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());

    return findMinCost(1, c, cuts);
}