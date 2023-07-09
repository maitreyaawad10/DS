#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    int row;
    int col;

    Node(int val, int i, int j)
    {
        data = val;
        row = i;
        col = j;
    }
};

class MyCmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return (a->data) > (b->data);
    }
};

int kSorted(vector<vector<int>> &a, int k, int n)
{
    priority_queue<Node *, vector<Node *>, MyCmp> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;

    for (int i = 0; i < k; ++i)
    {
        int currEle = a[i][0];
        mini = min(mini, currEle);
        maxi = max(maxi, currEle);
        Node *newNode = new Node(currEle, i, 0);
        minHeap.push(newNode);
    }

    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        Node *heapTop = minHeap.top();
        minHeap.pop();

        mini = heapTop->data;

        if ((maxi - mini) < (end - start))
        {
            start = mini;
            end = maxi;
        }

        int arrayNum = heapTop->row;
        int nextEleIndex = (heapTop->col) + 1;

        if (nextEleIndex < n)
        {
            int nextEle = a[arrayNum][nextEleIndex];
            maxi = max(maxi, nextEle);
            Node *newNode = new Node(nextEle, arrayNum, nextEleIndex);
            minHeap.push(newNode);
        }
        else
        {
            break;
        }
    }

    int ans = (end - start + 1);
    return ans;
}