#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// TC : O(N), SC : O(N)
vector<int> diagonal(Node *root)
{
    queue<Node *> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();

        while (currNode != NULL)
        {
            if (currNode->left != NULL)
                q.push(currNode->left);

            ans.push_back(currNode->data);
            currNode = currNode->right;
        }
    }

    return ans;
}