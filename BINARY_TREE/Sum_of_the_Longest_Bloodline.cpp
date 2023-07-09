#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// TC : O(N), SC : O(HEIGHT), BUT IN CASE OF SKEW TREE O(N)
void findSum(Node *root, int sum, int &maxSum, int &path, int currPath)
{
    if (root == NULL)
    {
        if (currPath > path)
        {
            maxSum = sum;
            path = currPath;
        }
        else if (currPath == path)
        {
            maxSum = max(sum, maxSum);
        }

        return;
    }

    sum = sum + (root->data);

    findSum(root->left, sum, maxSum, path, currPath + 1);
    findSum(root->right, sum, maxSum, path, currPath + 1);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int sum = 0, maxSum = INT_MIN, path = 0, currPath = 0;
    findSum(root, sum, maxSum, path, currPath);
    return maxSum;
}