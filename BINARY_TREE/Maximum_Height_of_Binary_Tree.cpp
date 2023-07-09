#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC : O(N), SC : O(N)

// USING SIMPLE RECURSION
int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftTree = maxDepth(root->left);
    int rightTree = maxDepth(root->right);

    int maxLen = max(leftTree, rightTree) + 1;

    return maxLen;
}

// USING BACKTRACKING
int findDepth(TreeNode *root, int currLen, int &maxLen)
{
    if (root == NULL)
    {
        maxLen = max(maxLen, currLen);
        return maxLen;
    }

    currLen += 1;
    findDepth(root->left, currLen, maxLen);
    findDepth(root->right, currLen, maxLen);
    currLen -= 1;

    return maxLen;
}

int maxDepth(TreeNode *root)
{
    int maxLen = INT_MIN, currLen = 0;

    return findDepth(root, currLen, maxLen);
}