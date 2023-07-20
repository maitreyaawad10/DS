#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(M)
int longestPalindromeSubsequence(string s)
{
    int n = s.length(), m = s.length();
    vector<int> dp(m + 1, 0), curr(m + 1, 0);

    string t = s;
    reverse(t.begin(), t.end());

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
int longestPalindromeSubsequence(string s)
{
    int n = s.length(), m = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    string t = s;
    reverse(t.begin(), t.end());

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= m; ++i)
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
int findLongestCommonSubsequence(int ind1, int ind2, string &s, string &t,
                                 vector<vector<int>> &dp)
{
    if (ind1 == 0 || ind2 == 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1 - 1] == t[ind2 - 1])
        return dp[ind1][ind2] = 1 + findLongestCommonSubsequence(ind1 - 1, ind2 - 1, s, t, dp);
    else
        return dp[ind1][ind2] = 0 + max(findLongestCommonSubsequence(ind1 - 1, ind2, s, t, dp),
                                        findLongestCommonSubsequence(ind1, ind2 - 1, s, t, dp));
}

int longestPalindromeSubsequence(string s)
{
    int n = s.length(), m = s.length();
    int ind1 = n, ind2 = m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    string t = s;
    reverse(t.begin(), t.end());

    return findLongestCommonSubsequence(ind1, ind2, s, t, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * N)
// SC: O(N + N)
int findLongestCommonSubsequence(int ind1, int ind2, string &s, string &t)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s[ind1] == t[ind2])
        return 1 + findLongestCommonSubsequence(ind1 - 1, ind2 - 1, s, t);
    else
        return 0 + max(findLongestCommonSubsequence(ind1 - 1, ind2, s, t),
                       findLongestCommonSubsequence(ind1, ind2 - 1, s, t));
}

int longestPalindromeSubsequence(string s)
{
    int n = s.length(), m = s.length();
    int ind1 = n - 1, ind2 = m - 1;

    string t = s;
    reverse(t.begin(), t.end());

    return findLongestCommonSubsequence(ind1, ind2, s, t);
}