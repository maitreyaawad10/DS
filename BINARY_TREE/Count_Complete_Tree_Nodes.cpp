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

// TC : O(logN)^2, SC : O(H)
int findLeftHeight(TreeNode *node)
{
    int height = 0;

    while (node != NULL)
    {
        height++;
        node = node->left;
    }

    return height;
}

int findRightHeight(TreeNode *node)
{
    int height = 0;

    while (node != NULL)
    {
        height++;
        node = node->right;
    }

    return height;
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}