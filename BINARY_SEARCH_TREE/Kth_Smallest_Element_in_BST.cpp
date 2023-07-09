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

// TC : O(H), SC : O(H)
int findInOrder(TreeNode *root, int k, int &count)
{
    if (root == NULL)
        return -1;

    // left
    int left = findInOrder(root->left, k, count);

    if (left != -1) // we have answer from left
        return left;

    // root/node
    count++;
    if (count == k) // we have answer in root node
        return root->val;

    // right
    return findInOrder(root->right, k, count);
}

int kthSmallest(TreeNode *root, int k)
{
    int count = 0;
    int ans = findInOrder(root, k, count);
    return ans;
}