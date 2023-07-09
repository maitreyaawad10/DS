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

// TC: O(N), SC: O(H)
class NodeValue
{
public:
    int maxValue;
    int minValue;
    bool isBST;
    int size;
};

NodeValue largestBSTHelper(TreeNode *root, int &maxSize)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    NodeValue leftTree = largestBSTHelper(root->left, maxSize);
    NodeValue rightTree = largestBSTHelper(root->right, maxSize);

    NodeValue currNode;

    currNode.maxValue = max(root->val, rightTree.maxValue);
    currNode.minValue = min(root->val, leftTree.minValue);
    currNode.size = leftTree.size + rightTree.size + 1;

    if (leftTree.isBST && rightTree.isBST && (root->val > leftTree.maxValue && root->val < rightTree.minValue))
        currNode.isBST = true;
    else
        currNode.isBST = false;

    if (currNode.isBST)
        maxSize = max(maxSize, currNode.size);

    return currNode;
}

int largestBST(TreeNode *root)
{
    int maxSize = 0;
    NodeValue ans = largestBSTHelper(root, maxSize);
    return maxSize;
}