#include <bits/stdc++.h>

using namespace std;

// APPROACH 4: DP, SPACE OPTIMIZATION
// TC: O(N * M)
// SC: O(M)
int lcs(string &s, string &t)
{
    int n = s.length(), m = t.length();
    vector<int> dp(m + 1), curr(m + 1, 0);

    for (int j = 0; j <= m; ++j)
        dp[j] = 0;

    int maxi = 0;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                curr[ind2] = 1 + dp[ind2 - 1];
                maxi = max(maxi, curr[ind2]);
            }
            else
            {
                curr[ind2] = 0;
            }
        }

        dp = curr;
    }

    return maxi;
}

// APPROACH 3: DP, TABULATION
// TC: O(N * M)
// SC: O(N * M)
int lcs(string &s, string &t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; ++j)
        dp[0][j] = 0;
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 0;

    int maxi = 0;

    for (int ind1 = 1; ind1 <= n; ++ind1)
    {
        for (int ind2 = 1; ind2 <= m; ++ind2)
        {
            if (s[ind1 - 1] == t[ind2 - 1])
            {
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                maxi = max(maxi, dp[ind1][ind2]);
            }
            else
                dp[ind1][ind2] = 0;
        }
    }

    return maxi;
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * M)
// SC: O(N * M) + O(N + M)
int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    if (s1[ind1] == s2[ind2])
        result = 1 + f(ind1 - 1, ind2 - 1, s1, s2, dp);
    else
        result = 0;

    return dp[ind1][ind2] = result;
}

int lcs(string &s, string &t)
{
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            f(i, j, s, t, dp);
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

// APPROACH 1: RECURSION
// TC: O(2 ^ N * 2 ^ M)
// SC: O(N + M)
int f(int ind1, int ind2, string &s1, string &s2, int &ans)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    int match = 0;

    if (s1[ind1] == s2[ind2])
    {
        match = 1 + f(ind1 - 1, ind2 - 1, s1, s2, ans);
        ans = max(ans, match);
    }

    int temp1 = f(ind1 - 1, ind2, s1, s2, ans);
    int temp2 = f(ind1, ind2 - 1, s1, s2, ans);

    return match;
}

int lcs(string &s, string &t)
{
    int ans = 0;
    int n = s.length(), m = t.length();

    f(n - 1, m - 1, s, t, ans);

    return ans;
}