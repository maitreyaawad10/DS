#include <bits/stdc++.h>

using namespace std;

int getMedian(int currElement, priority_queue<int> &maxHeap,
              priority_queue<int, vector<int>, greater<int>> &minHeap, vector<int> &ans)
{

    int sizeMaxi = maxHeap.size(), sizeMini = minHeap.size();

    if (sizeMaxi > sizeMini)
    {
        if (currElement > maxHeap.top())
        {
            minHeap.push(currElement);
        }
        else
        {
            maxHeap.push(currElement);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        return (maxHeap.top() + minHeap.top()) / 2;
    }
    else
    {
        if (currElement < ans.back())
        {
            maxHeap.push(currElement);
        }
        else
        {
            minHeap.push(currElement);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        return maxHeap.top();
    }
}

vector<int> findMedian(vector<int> &arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    maxHeap.push(arr[0]);
    vector<int> ans;
    ans.push_back(arr[0]);

    for (int i = 1; i < n; ++i)
    {
        int median = getMedian(arr[i], maxHeap, minHeap, ans);
        ans.push_back(median);
    }

    return ans;
}
