#include <bits/stdc++.h>

using namespace std;

// 1 2 3 1 4 5 2 3 6
vector<int> max_of_subarrays(int *A, int n, int k)
{
    deque<int> maxQ;

    vector<int> ans;

    int i = 0, j = 0;

    while (j < n)
    {
        while (!maxQ.empty() && A[maxQ.back()] < A[j])
        {
            maxQ.pop_back();
        }
        maxQ.push_back(j);

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            ans.push_back(A[maxQ.front()]);

            i++;
            if (maxQ.front() < i)
                maxQ.pop_front();
            j++;
        }
    }

    return ans;
}