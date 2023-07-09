#include <bits/stdc++.h>

using namespace std;

// LEETCODE
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    vector<int> levels;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        int currQueueSize = q.size();
        vector<int> levels;

        for (int i = 0; i < currQueueSize; ++i)
        {
            TreeNode *currNode = q.front();
            q.pop();

            if (currNode->left != NULL)
                q.push(currNode->left);
            if (currNode->right != NULL)
                q.push(currNode->right);

            levels.push_back(currNode->val);
        }

        ans.push_back(levels);
    }

    return ans;
}

// CODESTUDIO

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> getLevelOrder(BinaryTreeNode *root)
{
    queue<BinaryTreeNode *> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode *node = q.front();
        q.pop();

        ans.push_back(node->data);

        if (node->left != NULL)
        {
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            q.push(node->right);
        }
    }

    return ans;
}