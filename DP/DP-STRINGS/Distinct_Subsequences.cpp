#include <bits/stdc++.h>

using namespace std;

// APPROACH 5: DP, ULTRA SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(M)
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<double> dp(m + 1, 0);

    dp[0] = 1;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = m; ind2 >= 1; --ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                dp[ind2] = dp[ind2 - 1] + dp[ind2];
            else
                dp[ind2] = dp[ind2];
        }
    }

    return (int)dp[m];
}

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(2M)
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<double> dp(m + 1, 0), curr(m + 1, 0);

    dp[0] = curr[0] = 1;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                curr[ind2] = dp[ind2 - 1] + dp[ind2];
            else
                curr[ind2] = dp[ind2];
        }

        dp = curr;
    }

    return (int)dp[m];
}

// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
                dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1] + dp[ind1 - 1][ind2];
            else
                dp[ind1][ind2] = dp[ind1 - 1][ind2];
        }
    }

    return (int)dp[n][m];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp)
{
    if (ind2 == 0)
        return 1;

    if (ind1 == 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s[ind1 - 1] == t[ind2 - 1])
        return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, s, t, dp) + f(ind1 - 1, ind2, s, t, dp);
    else
        return dp[ind1][ind2] = f(ind1 - 1, ind2, s, t, dp);
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, s, t, dp);
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * 2 ^ M)
// SC: O(N + M)
int f(int ind1, int ind2, string &s, string &t)
{
    if (ind2 < 0)
        return 1;

    if (ind1 < 0)
        return 0;

    if (s[ind1] == t[ind2])
        return f(ind1 - 1, ind2 - 1, s, t) + f(ind1 - 1, ind2, s, t);
    else
        return f(ind1 - 1, ind2, s, t);
}

int numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    return f(n - 1, m - 1, s, t);
}