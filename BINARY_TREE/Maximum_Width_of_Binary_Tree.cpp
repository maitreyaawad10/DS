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
int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;

    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    int maxWidth = INT_MIN;

    while (!q.empty())
    {
        int size = q.size();

        int startIndex = q.front().second;
        int endIndex = q.back().second;

        maxWidth = max(maxWidth, endIndex - startIndex + 1);

        for (int i = 0; i < size; ++i)
        {
            pair<TreeNode *, int> nodeIndexPair = q.front();
            TreeNode *currNode = nodeIndexPair.first;
            int nodeIndex = nodeIndexPair.second - startIndex;

            q.pop();

            if (currNode->left != NULL)
                q.push({currNode->left, 2LL * nodeIndex + 1});
            if (currNode->right != NULL)
                q.push({currNode->right, 2LL * nodeIndex + 2});
        }
    }

    return maxWidth;
}