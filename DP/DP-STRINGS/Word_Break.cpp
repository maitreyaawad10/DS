#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;

// APPROACH 3: DP, TABULATION
// TC: O(N * N)
// SC: O(N)
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;

    for (auto value : wordDict)
        st.insert(value);

    int n = s.size();
    vector<int> dp(n + 1, 0);

    dp[0] = true;

    for (int index = 1; index <= n; ++index)
    {
        bool flag = false;

        for (int i = index; i > 0; --i)
        {
            bool currPartition = false;

            if (st.find(s.substr(i - 1, index - i + 1)) != st.end())
                currPartition = true;

            bool nextPartition = dp[i - 1];

            if (currPartition && nextPartition)
            {
                flag = true;
                dp[index] = true;
            }
        }

        if (flag == false)
            dp[index] = false;
    }

    return dp[n];
}

// APPROACH 2: DP, MEMOIZATION
// TC: O(N * N)
// SC: O(N) + O(N)
/*
RIGHT SHIFTED INDEXES, BETTER FOR TABULATION
bool findAns(int index, string &s, unordered_set<string> st, vector<int> &dp) {
    if (index == 0)
        return true;

    if (dp[index] != -1)
        return dp[index];

    for (int i = index; i > 0; --i) {
        bool currPartition = false;

        if (st.find(s.substr(i - 1, index - i + 1)) != st.end())
            currPartition = true;

        bool nextPartition = findAns(i - 1, s, st, dp);

        if (currPartition && nextPartition)
            return dp[index] = true;
    }

    return dp[index] = false;
}

public:
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> st;

    for (auto value: wordDict)
        st.insert(value);

    int n = s.size();
    vector<int> dp(n + 2, -1);

    int index = n;
    return findAns(index, s, st, dp);
}
*/

bool findAns(int index, string &s, unordered_set<string> st, vector<int> &dp)
{
    if (index < 0)
        return true;

    if (dp[index] != -1)
        return dp[index];

    for (int i = index; i >= 0; --i)
    {
        bool currPartition = false;

        if (st.find(s.substr(i, index - i + 1)) != st.end())
            currPartition = true;

        bool nextPartition = findAns(i - 1, s, st, dp);

        if (currPartition && nextPartition)
            return dp[index] = true;
    }

    return dp[index] = false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;

    for (auto value : wordDict)
        st.insert(value);

    int n = s.size();
    vector<int> dp(n + 1, -1);

    int index = n - 1;
    return findAns(index, s, st, dp);
}

// APPROACH 1: RECURSION
// TC: O((2 ^ N) * N)
// SC: O(N)
bool findAns(int index, string &s, unordered_set<string> st)
{
    if (index < 0)
        return true;

    for (int i = index; i >= 0; --i)
    {
        bool currPartition = false;

        if (st.find(s.substr(i, index - i + 1)) != st.end())
            currPartition = true;

        bool nextPartition = findAns(i - 1, s, st);

        if (currPartition && nextPartition)
            return true;
    }

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> st;

    for (auto value : wordDict)
        st.insert(value);

    int index = s.size() - 1;
    return findAns(index, s, st);
}