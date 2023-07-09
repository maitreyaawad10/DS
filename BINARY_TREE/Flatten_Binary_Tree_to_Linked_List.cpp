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

// TC : O(N), SC : O(1)
void flatten(TreeNode *root)
{
    TreeNode *currNode = root;
    TreeNode *nextNode = NULL;

    while (currNode != NULL)
    {
        if (currNode->left != NULL)
        {
            nextNode = currNode->left;

            while (nextNode->right != NULL)
            {
                nextNode = nextNode->right;
            }

            nextNode->right = currNode->right;
            currNode->right = currNode->left;
            currNode->left = NULL;
        }

        currNode = currNode->right;
    }
}