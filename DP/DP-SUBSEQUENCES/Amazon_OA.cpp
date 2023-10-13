#include <bits/stdc++.h>

using namespace std;

/*
    QUES: Given n and m, find the minimum number of primes required to make n
    INPUT: N = 10, M = 1
    OUTPUT: 5 (2 + 2 + 2 + 2 + 2)
    INPUT: N = 11, M = 3
    OUTPUT: 3 (5 + 3 + 3)
*/

bool sieve[101];
vector<int> a;

// PRIMES CALCULATION USING SIEVE
void primes(int m)
{
    sieve[0] = sieve[1] = false;

    for (int i = 2; i <= 100; ++i)
        sieve[i] = true;

    for (int i = 2; i * i <= m; ++i)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= m; j += i)
                sieve[j] = false;
        }
    }

    for (int i = 2; i <= 100; ++i)
    {
        if (sieve[i])
            a.push_back(i);
    }
}

// MEMOIZATION
int f(int index, int n, vector<vector<int>> &dp)
{
    // base case
    if (n == 0)
        return 0;

    if (index == 0)
    {
        if (n % a[0] == 0)
            return (n / a[0]);
        return 1e9;
    }

    if (dp[index][n] != -1)
        return dp[index][n];

    int notPick = 0 + f(index - 1, n, dp);
    int pick = 1e9;

    if (abs(n - a[index]) != 1)
        pick = 1 + f(index, n - a[index], dp);

    return dp[index][n] = min(pick, notPick);
}

int main()
{
    int n = 11, m = 3;
    primes(100);

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = f(m - 1, n, dp);

    cout << "Ans : " << ans << endl;

    return 0;
}

// TABULATION
int fTab(int n, int m)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; ++i)
    {
        if (i % a[0] == 0)
            dp[0][i] = i / a[0];
        else
            dp[0][i] = 1e9;
    }

    for (int index = 1; index < m; ++index)
    {
        for (int currP = 1; currP <= n; ++currP)
        {
            int notPick = 0 + dp[index - 1][currP];
            int pick = 1e9;

            if ((a[index] <= currP) && ((currP - a[index]) != 1))
                pick = 1 + dp[index][currP - a[index]];

            dp[index][currP] = min(pick, notPick);
        }
    }

    return dp[m - 1][n];
}

int main()
{
    int n = 10, m = 1;
    primes(100);

    cout << "Ans : " << fTab(n, m) << endl;

    return 0;
}

// TABULATION - SPACE OPTIMIZATION
int fTab(int n, int m)
{
    vector<int> dp(n + 1, 0), curr(n + 1, 0);

    for (int i = 0; i <= n; ++i)
    {
        if (i % a[0] == 0)
            dp[i] = i / a[0];
        else
            dp[i] = 1e9;
    }

    for (int index = 1; index < m; ++index)
    {
        for (int currP = 1; currP <= n; ++currP)
        {
            int notPick = 0 + dp[currP];
            int pick = 1e9;

            if ((a[index] <= currP) && ((currP - a[index]) != 1))
                pick = 1 + curr[currP - a[index]];

            curr[currP] = min(pick, notPick);
        }

        dp = curr;
    }

    return dp[n];
}

int main()
{
    int n = 11, m = 3;
    primes(100);

    cout << "Ans : " << fTab(n, m) << endl;

    return 0;
}
