#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(2M)
int minDistance(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> dp(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; ++j)
        dp[j] = j;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        curr[0] = ind1;
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                curr[ind2] = 0 + dp[ind2 - 1];
            else
                curr[ind2] = 1 + min(curr[ind2 - 1], min(dp[ind2], dp[ind2 - 1]));
        }

        dp = curr;
    }

    return dp[m];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
int minDistance(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; ++j)
        dp[0][j] = j;

    for (int i = 0; i <= n; ++i)
        dp[i][0] = i;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                dp[ind1][ind2] = 0 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 1 + min(dp[ind1][ind2 - 1], min(dp[ind1 - 1][ind2], dp[ind1 - 1][ind2 - 1]));
        }
    }

    return dp[n][m];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
int findMinOperations(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
    if (ind1 == 0)
        return ind2;
    if (ind2 == 0)
        return ind1;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1 - 1] == t[ind2 - 1])
        return dp[ind1][ind2] = 0 + findMinOperations(ind1 - 1, ind2 - 1, s, t, dp);
    else
        return dp[ind1][ind2] = 1 + min(findMinOperations(ind1, ind2 - 1, s, t, dp),
                                        min(findMinOperations(ind1 - 1, ind2, s, t, dp),
                                            findMinOperations(ind1 - 1, ind2 - 1, s, t, dp)));
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return findMinOperations(n, m, word1, word2, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * 2 ^ M)
// SC: O(N + M)
int findMinOperations(int ind1, int ind2, string s, string t)
{
    if (ind1 < 0)
        return ind2 + 1;
    if (ind2 < 0)
        return ind1 + 1;

    if (s[ind1] == t[ind2])
        return 0 + findMinOperations(ind1 - 1, ind2 - 1, s, t);
    else
        return 1 + min(findMinOperations(ind1, ind2 - 1, s, t),
                       min(findMinOperations(ind1 - 1, ind2, s, t),
                           findMinOperations(ind1 - 1, ind2 - 1, s, t)));
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    return findMinOperations(n - 1, m - 1, word1, word2);
}