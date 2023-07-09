#include <bits/stdc++.h>

using namespace std;

vector<int> firstNegative(vector<int> A, int n, int k)
{
    deque<int> dq;
    vector<int> ans;

    int i = 0, j = 0;

    while (j < n)
    {
        if (A[j] < 0)
            dq.push_back(j);

        if ((j - i + 1) < k) // REACHING THE WINDOW SIZE
            j++;

        else if ((j - i + 1) == k) // REACHED THE WINDOW SIZE
        {
            if (dq.empty())
                ans.push_back(0);
            else
                ans.push_back(A[dq.front()]);

            // SLIDING THE WINDOW
            i++;
            if (!dq.empty() && dq.front() < i)
                dq.pop_front();
            j++;
        }
    }

    return ans;
}