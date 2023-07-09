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

// TC : O(N), SC : O(H)
bool symmetrical(TreeNode *leftTree, TreeNode *rightTree)
{
    if (leftTree == NULL || rightTree == NULL)
        return leftTree == rightTree;

    if (leftTree->val != rightTree->val)
        return false;

    return symmetrical(leftTree->left, rightTree->right) && symmetrical(leftTree->right, rightTree->left);
}

bool isSymmetric(TreeNode *root)
{
    return root == NULL || symmetrical(root->left, root->right);
}