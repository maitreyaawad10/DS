#include <bits/stdc++.h>

using namespace std;

// USING SINGLE QUEUE
// TC : O(N), SC : O(N)
queue<int> q;

void push(int x)
{
    q.push(x);

    for (int i = 0; i < q.size() - 1; ++i)
    {
        int top = q.front();
        q.pop();
        q.push(top);
    }
}

int pop()
{
    if (!q.empty())
    {
        int top = q.front();
        q.pop();
        return top;
    }

    return -1;
}

int top()
{
    if (!q.empty())
        return q.front();

    return -1;
}

bool empty()
{
    if (q.empty())
        return true;

    return false;
}

// USING TWO QUEUES
// TC : O(N), SC : O(N)
queue<int> q1, q2;

void push(int x)
{
    q2.push(x);

    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);
}

int pop()
{
    if (!q1.empty())
    {
        int top = q1.front();
        q1.pop();
        return top;
    }

    return -1;
}

int top()
{
    if (!q1.empty())
        return q1.front();

    return -1;
}

bool empty()
{
    if (q1.empty())
        return true;

    return false;
}
