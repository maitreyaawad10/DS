#include<bits/stdc++.h>

using namespace std;

vector<int> findNextSmaller(vector<int>& heights, int n) {
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

vector<int> findPrevSmaller(vector<int>& heights, int n) {
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(i);
    }

    return ans;
}


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();

    vector<int> next(n);
    next = findNextSmaller(heights, n);

    vector<int> prev(n);
    prev = findPrevSmaller(heights, n);

    int area = INT_MIN;

    // for (auto value: next)
    //     cout << value << " ";
    // cout << endl;

    // for (auto value: prev)
    //     cout << value << " ";
    // cout << endl;

    for (int i = 0; i < n; ++i) {
        int nextSmallerIndex = next[i];

        if (nextSmallerIndex == -1)
            nextSmallerIndex = n;

        int prevSmallerIndex = prev[i];

        int length = heights[i];

        int breadth = nextSmallerIndex - prevSmallerIndex - 1;

        int newArea = length * breadth;

        area = max(area, newArea);
    }

    return area;
}
