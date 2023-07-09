#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// TC : O(N)
// SC : O(N)
Node *nodeToParentMapping(Node *root, unordered_map<Node *, Node *> &mp, int target)
{
    queue<Node *> q;
    q.push(root);

    Node *targetNode = NULL;

    mp[root] = NULL;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            Node *currNode = q.front();
            q.pop();

            if (currNode->data == target)
                targetNode = currNode;

            if (currNode->left != NULL)
            {
                q.push(currNode->left);
                mp[currNode->left] = currNode;
            }

            if (currNode->right != NULL)
            {
                q.push(currNode->right);
                mp[currNode->right] = currNode;
            }
        }
    }

    return targetNode;
}

int burnTree(Node *targetNode, unordered_map<Node *, Node *> &mp)
{
    unordered_map<Node *, bool> visited;
    queue<Node *> q;
    q.push(targetNode);
    visited[targetNode] = true;

    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = false; // for checking if new nodes burned so to increment time

        for (int i = 0; i < size; ++i)
        {
            Node *currNode = q.front();
            q.pop();

            // if currnode -> left is non null and not visited
            if ((currNode->left != NULL) && (!visited[currNode->left]))
            {
                q.push(currNode->left);
                visited[currNode->left] = true;
                flag = true;
            }

            // if currnode -> right is non null and not visited
            if ((currNode->right != NULL) && (!visited[currNode->right]))
            {
                q.push(currNode->right);
                visited[currNode->right] = true;
                flag = true;
            }

            // if currnode -> parent is non null and not visited
            if ((mp[currNode] != NULL) && (!visited[mp[currNode]]))
            {
                q.push(mp[currNode]);
                visited[mp[currNode]] = true;
                flag = true;
            }
        }

        if (flag == true)
            time++;
    }

    return time;
}

int minTime(Node *root, int target)
{
    unordered_map<Node *, Node *> mp;

    Node *targetNode = nodeToParentMapping(root, mp, target);

    int ans = burnTree(targetNode, mp);

    return ans;
}