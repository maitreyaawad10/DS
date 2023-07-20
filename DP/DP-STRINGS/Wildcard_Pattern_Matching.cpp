#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(2M)
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<bool> dp(n + 1, false), curr(m + 1, false);
    dp[0] = true;

    for (int j = 1; j <= m; ++j)
        dp[j] = false;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        bool flag = true;

        for (int curr = 1; curr <= ind1; ++curr)
        {
            if (pattern[curr - 1] != '*')
            {
                flag = false;
                break;
            }
        }

        curr[0] = flag;

        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (pattern[ind1 - 1] == text[ind2 - 1] || pattern[ind1 - 1] == '?')
                curr[ind2] = dp[ind2 - 1];

            else if (pattern[ind1 - 1] == '*')
                curr[ind2] = dp[ind2] || curr[ind2 - 1];

            else
                curr[ind2] = false;
        }

        dp = curr;
    }

    return dp[m];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, -1));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j)
        dp[0][j] = false;

    for (int i = 1; i <= n; ++i)
    {
        bool flag = true;

        for (int curr = 1; curr <= i; ++curr)
        {
            if (pattern[curr - 1] != '*')
                flag = false;
        }

        dp[i][0] = flag;
    }

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (pattern[ind1 - 1] == text[ind2 - 1] || pattern[ind1 - 1] == '?')
                dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];

            else if (pattern[ind1 - 1] == '*')
                dp[ind1][ind2] = dp[ind1 - 1][ind2] || dp[ind1][ind2 - 1];

            else
                dp[ind1][ind2] = false;
        }
    }

    return dp[n][m];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
bool f(int ind1, int ind2, string &pattern, string &text, vector<vector<int>> &dp)
{
    if (ind1 == 0 && ind2 == 0)
        return true;
    if (ind1 == 0 && ind2 > 0)
        return false;
    if (ind2 == 0 && ind1 > 0)
    {
        for (int curr = 1; curr <= ind1; ++curr)
        {
            if (pattern[curr - 1] != '*')
                return false;
        }

        return true;
    }

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (pattern[ind1 - 1] == text[ind2 - 1] || pattern[ind1 - 1] == '?')
        return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, pattern, text, dp);
    else if (pattern[ind1 - 1] == '*')
        return dp[ind1][ind2] = f(ind1 - 1, ind2, pattern, text, dp) || f(ind1, ind2 - 1, pattern, text, dp);
    else
        return dp[ind1][ind2] = false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, pattern, text, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * 2 ^ M)
// SC: O(N + M)
bool f(int ind1, int ind2, string &pattern, string &text)
{
    if (ind1 < 0 && ind2 < 0)
        return true;
    if (ind1 < 0 && ind2 >= 0)
        return false;
    if (ind2 < 0 && ind1 >= 0)
    {
        for (int curr = 0; curr <= ind1; ++curr)
        {
            if (pattern[curr] != '*')
                return false;
        }

        return true;
    }

    if (pattern[ind1] == text[ind2] || pattern[ind1] == '?')
        return f(ind1 - 1, ind2 - 1, pattern, text);
    else if (pattern[ind1] == '*')
        return f(ind1 - 1, ind2, pattern, text) || f(ind1, ind2 - 1, pattern, text);
    else
        return false;
}

bool wildcardMatching(string pattern, string text)
{
    int n = pattern.length(), m = text.length();
    return f(n - 1, m - 1, pattern, text);
}