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

// TC: O(N), SC: O(1)
TreeNode *buildTree(vector<int> &preorder, int &upperBound, int &index)
{
    if (index >= preorder.size() || preorder[index] > upperBound)
        return NULL;

    TreeNode *root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, root->val, index);
    root->right = buildTree(preorder, upperBound, index);

    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int upperBound = INT_MAX, index = 0;

    return buildTree(preorder, upperBound, index);
}