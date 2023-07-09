#include <bits/stdc++.h>

using namespace std;

// TC : O(N * (M + N))
// SC : O(N)
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);

    for (int i = n - 1; i >= 0; --i)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<int> st;

    st.push(-1);

    for (int i = 0; i < n; ++i)
    {
        while (st.top() != -1 && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; ++i)
    {
        int length = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }

        int breadth = next[i] - prev[i] - 1;

        int newArea = length * breadth;
        area = max(area, newArea);
    }

    return area;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    vector<int> heights(m, 0);
    int maxArea = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (mat[i][j] == 1)
                heights[j]++;
            else
                heights[j] = 0;
        }

        int area = largestRectangleArea(heights);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}