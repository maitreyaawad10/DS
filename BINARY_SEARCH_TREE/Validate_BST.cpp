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

// TC : O(N), SC: O(LOG N)
bool isValid(TreeNode *root, long min, long max)
{
    if (root == NULL)
        return true;

    if (root->val >= max || root->val <= min)
        return false;

    bool left = isValid(root->left, min, root->val);
    bool right = isValid(root->right, root->val, max);

    return left && right;
}

bool isValidBST(TreeNode *root)
{
    return isValid(root, LONG_MIN, LONG_MAX);
}