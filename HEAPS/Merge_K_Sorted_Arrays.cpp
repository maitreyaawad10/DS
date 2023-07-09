#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int value;
    int index;
    int arrayNumber;

    node(int value, int index, int arrayNumber)
    {
        this->value = value;
        this->index = index;
        this->arrayNumber = arrayNumber;
    }
};

// TC: O(N * log(K)))
// SC: O(K)
class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->value > b->value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; ++i)
    {
        node *newNode = new node(kArrays[i][0], 0, i);
        minHeap.push(newNode);
    }

    vector<int> ans;

    while (!minHeap.empty())
    {
        node *heapTop = minHeap.top();
        ans.push_back(heapTop->value);
        minHeap.pop();

        int nextIndex = (heapTop->index) + 1;
        int currArray = heapTop->arrayNumber;

        if ((nextIndex) < kArrays[currArray].size())
        {
            node *newNode = new node(kArrays[currArray][nextIndex], nextIndex, currArray);
            minHeap.push(newNode);
        }
    }

    return ans;
}
