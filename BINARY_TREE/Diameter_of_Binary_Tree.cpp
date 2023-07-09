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

// TC : O(N), SC : O(HEIGHT)
pair<int, int> diameterFast(TreeNode *root)
{
    if (root == NULL)
    {
        return make_pair(0, 0);
    }

    pair<int, int> leftTree = diameterFast(root->left);   // diameter lies in left subtree
    pair<int, int> rightTree = diameterFast(root->right); // diameter lies in right subtree

    int tempAns = (leftTree.second + rightTree.second) + 1; // diameter passes through root

    pair<int, int> ans;

    ans.first = max(tempAns, max(leftTree.first, rightTree.first)); // DIAMETER
    ans.second = max(leftTree.second, rightTree.second) + 1;        // HEIGHT

    return ans;
}

int diameter(TreeNode *root)
{
    return diameterFast(root).first;
}

// TC : O(N^2), SC : O(HEIGHT)
int height(TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int treeHeight = max(left, right) + 1;

    return treeHeight;
}

int diameter(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftTree = diameter(root->left);
    int rightTree = diameter(root->right);

    int diameter = (height(root->left) + height(root->right)) + 1;

    int ans = max(diameter, max(leftTree, rightTree));

    return ans;
}