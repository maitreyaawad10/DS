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
pair<bool, int> balancedFast(TreeNode *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = {true, 0};
        return p;
    }

    pair<bool, int> leftTree = balancedFast(root->left);
    pair<bool, int> rightTree = balancedFast(root->right);

    bool leftBalanced = leftTree.first;
    bool rightBalanced = rightTree.first;

    bool diff = abs(leftTree.second - rightTree.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftTree.second, rightTree.second) + 1;

    if (leftBalanced && rightBalanced && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}

bool isBalanced(TreeNode *root)
{
    return balancedFast(root).first;
}