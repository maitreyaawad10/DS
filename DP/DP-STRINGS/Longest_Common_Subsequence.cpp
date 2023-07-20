#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(M)
int lcs(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<int> dp(m + 1), curr(m + 1, 0);

    for (int j = 0; j <= m; ++j)
        dp[j] = 0;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                curr[ind2] = 1 + dp[ind2 - 1];
            else
                curr[ind2] = 0 + max(dp[ind2], curr[ind2 - 1]);
        }

        dp = curr;
    }

    return dp[m];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
int lcs(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    return dp[n][m];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
int findLCS(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1] == t[ind2])
        return dp[ind1][ind2] = 1 + findLCS(ind1 - 1, ind2 - 1, s, t, dp);

    return dp[ind1][ind2] = 0 + max(findLCS(ind1 - 1, ind2, s, t, dp), findLCS(ind1, ind2 - 1, s, t, dp));
}

int lcs(string s, string t)
{
    int n = s.length(), m = t.length();
    int ind1 = n - 1, ind2 = m - 1;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return findLCS(ind1, ind2, s, t, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * 2 ^ M)
// SC: O(N + M)
int findLCS(int ind1, int ind2, string &s, string &t)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s[ind1] == t[ind2])
        return 1 + findLCS(ind1 - 1, ind2 - 1, s, t);

    return 0 + max(findLCS(ind1 - 1, ind2, s, t), findLCS(ind1, ind2 - 1, s, t));
}

int lcs(string s, string t)
{
    int ind1 = s.length() - 1, ind2 = t.length() - 1;
    return findLCS(ind1, ind2, s, t);
}