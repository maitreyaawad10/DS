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

// TC : O(LOG N), SC: O(LOG N)
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->val > key)
        root->left = deleteNode(root->left, key);

    else if (root->val < key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL) // node to be deleted has 0 or 1 children
            return root->right;

        else if (root->right == NULL) // node to be deleted has 0 or 1 children
            return root->left;

        else
        { // node to be deleted has 2 children
            // find the minimum value from root's right subtree
            TreeNode *currNode = root->right;

            while (currNode->left != NULL)
                currNode = currNode->left;

            // replace the root's value(node to be deleted value) with the min value
            root->val = currNode->val;
            root->right = deleteNode(root->right, root->val);
        }
    }

    return root;
}