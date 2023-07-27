#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// TC: O(N)
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int minCut(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);

    dp[n] = 0;

    for (int index = n - 1; index >= 0; --index)
    {
        int minCuts = INT_MAX;

        for (int j = index; j < n; ++j)
        {
            if (isPalindrome(index, j, s))
            {
                int currCuts = 1 + dp[j + 1];
                minCuts = min(minCuts, currCuts);
            }
        }

        dp[index] = minCuts;
    }

    return dp[0] - 1;
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N) + O(N)
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int findMinCuts(int index, int n, string &s, vector<int> &dp)
{
    if (index == n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int minCuts = INT_MAX;

    for (int j = index; j < n; ++j)
    {
        if (isPalindrome(index, j, s))
        {
            int currCuts = 1 + findMinCuts(j + 1, n, s, dp);
            minCuts = min(minCuts, currCuts);
        }
    }

    return dp[index] = minCuts;
}

int minCut(string s)
{
    int n = s.length();
    vector<int> dp(n, -1);

    return findMinCuts(0, n, s, dp) - 1;
}

// APPROACH 1: RECURSION
// TC: O(2 ^ (N * N))
// SC: O(N)
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int findMinCuts(int index, int n, string &s)
{
    if (index == n)
        return 0;

    int minCuts = INT_MAX;

    for (int j = index; j < n; ++j)
    {
        if (isPalindrome(index, j, s))
        {
            int currCuts = 1 + findMinCuts(j + 1, n, s);
            minCuts = min(minCuts, currCuts);
        }
    }

    return minCuts;
}

int minCut(string s)
{
    int n = s.length();

    return findMinCuts(0, n, s) - 1;
}