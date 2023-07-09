#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElements(vector<int> &arr)
{
    int n = arr.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 2; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        st.push(arr[i]);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
            st.pop();

        ans[i] = st.size() == 0 ? -1 : st.top();
        st.push(arr[i]);
    }

    return ans;
}