#include <bits/stdc++.h>

using namespace std;

// USING SINGLE STACKS
// TC : O(1)
// SC : O(2N)
stack<long long> st;
long long mini = INT_MAX;

void push(int val)
{
    long long value = val;

    if (st.empty())
    {
        mini = value;
        st.push(value);
    }
    else
    {
        if (value < mini)
        {
            st.push((2 * value) - mini);
            mini = value;
        }
        else
        {
            st.push(value);
        }
    }
}

void pop()
{
    if (st.empty())
        return;

    if (st.top() < mini)
    {
        mini = (2 * mini) - st.top();
    }
    st.pop();
}

int top()
{
    if (st.top() < mini)
    {
        return mini;
    }
    return st.top();
}

int getMin()
{
    return mini;
}

// USING TWO STACKS
// TC : O(1)
// SC : O(2N)
stack<int> s1;
stack<int> s2;

int mini = INT_MAX;

void push(int val)
{
    s1.push(val);
    mini = s2.empty() ? val : min(s2.top(), val);
    s2.push(mini);
}

void pop()
{
    s1.pop();
    s2.pop();
}

int top()
{
    if (!s1.empty())
        return s1.top();
    return INT_MAX;
}

int getMin()
{
    if (!s2.empty())
        return s2.top();
    return INT_MAX;
}