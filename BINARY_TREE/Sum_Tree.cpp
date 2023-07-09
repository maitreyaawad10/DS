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
pair<bool, int> sumFast(TreeNode *root)
{
    // BASE CASE FOR NULL NODE
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }

    // LEAF NODE - RETURN TRUE AND VALUE OF ROOT NODE
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = {true, root->val};
        return p;
    }

    pair<bool, int> leftTree = sumFast(root->left);
    pair<bool, int> rightTree = sumFast(root->right);

    bool sum = (leftTree.second + rightTree.second) == (root->val);

    pair<bool, int> ans;
    ans.second = leftTree.second + rightTree.second + root->val;

    if (leftTree.first && rightTree.first && sum)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isSumTree(TreeNode *root)
{
    return sumFast(root).first;
}