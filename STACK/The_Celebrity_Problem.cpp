#include <bits/stdc++.h>

using namespace std;

// APPROACH 3 : OPTIMAL APPROACH (USING TWO POINTER APPROACH)
// TC : O(N)
// SC : O(1)
int celebrity(vector<vector<int>> &M, int n)
{
    int left = 0, right = n - 1;

    while (left < right)
    {
        if (M[left][right] == 1)
            left++;
        else
            right--;
    }

    int candidate = left;

    int zeroCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (M[candidate][i] == 0)
            zeroCount++;
    }

    if (zeroCount != n)
        return -1;

    int oneCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (M[i][candidate] == 1)
            oneCount++;
    }

    if (oneCount != n - 1)
        return -1;

    return candidate;
}

// APPROACH 2 : BETTER APPROACH (USING STACK DS)
// TC : O(N)
// SC : O(N)
bool knows(vector<vector<int>> &M, int a, int b)
{
    if (M[a][b] == 1)
        return true;

    return false;
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        st.push(i);
    }

    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (knows(M, a, b))
            st.push(b);
        else
            st.push(a);
    }

    int candidate = st.top();

    int zeroCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (M[candidate][i] == 0)
            zeroCount++;
    }

    if (zeroCount != n)
        return -1;

    int oneCount = 0;
    for (int i = 0; i < n; ++i)
    {
        if (M[i][candidate] == 1)
            oneCount++;
    }

    if (oneCount != n - 1)
        return -1;

    return candidate;
}

// APPROACH 1 : BRUTE FORCE
// TC : O(N*(N + M)) = O(N*N)
// SC : O(1)
