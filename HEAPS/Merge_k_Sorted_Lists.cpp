#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// OPTIMAL APPROACH
// TC: O(N * log(K)))
// SC: O(LOG K)
ListNode *merge2SortedLL(ListNode *left, ListNode *right)
{
    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    ListNode *dummyNode = new ListNode(1000000);
    ListNode *currNode = dummyNode;

    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            currNode->next = left;
            left = left->next;
        }
        else
        {
            currNode->next = right;
            right = right->next;
        }

        currNode = currNode->next;
    }

    if (left != NULL)
        currNode->next = left;
    if (right != NULL)
        currNode->next = right;

    return dummyNode->next;
}

ListNode *mergekListsHelper(vector<ListNode *> &lists, int start, int end)
{
    if (start > end)
        return NULL;

    if (start == end) // we have only one LL
        return lists[start];

    int mid = start + (end - start) / 2;
    ListNode *leftHalf = mergekListsHelper(lists, start, mid);
    ListNode *rightHalf = mergekListsHelper(lists, mid + 1, end);

    return merge2SortedLL(leftHalf, rightHalf);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;

    return mergekListsHelper(lists, 0, lists.size() - 1);
}

// TC: O(N * log(K)))
// SC: O(K)
class myCmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return (a->val) > (b->val);
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, myCmp> minHeap;
        int k = lists.size();

        for (int i = 0; i < k; ++i)
        {
            if (lists[i] != NULL)
                minHeap.push(lists[i]);
        }

        ListNode *newHead = new ListNode(1000000); // initialized head with dummy value
        ListNode *currNode = newHead;

        while (!minHeap.empty())
        {
            ListNode *heapTop = minHeap.top();
            minHeap.pop();

            currNode->next = heapTop;
            currNode = currNode->next;

            if (heapTop->next != NULL)
            {
                minHeap.push(heapTop->next);
            }
        }

        return newHead->next;
    }
};