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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;

    if (root == NULL)
        return ans;

    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> levels(size);

        for (int i = 0; i < size; ++i)
        {
            TreeNode *currNode = q.front();
            q.pop();

            int index = leftToRight ? i : (size - 1 - i);
            levels[index] = currNode->val;

            if ((currNode->left) != NULL)
            {
                q.push(currNode->left);
            }
            if ((currNode->right) != NULL)
            {
                q.push(currNode->right);
            }
        }

        leftToRight = !leftToRight;
        ans.push_back(levels);
    }

    return ans;
}