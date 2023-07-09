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
int findMaxPathSum(TreeNode *root, int &ans)
{
    if (root == NULL)
        return 0;

    int leftPathMax = findMaxPathSum(root->left, ans);
    int rightPathMax = findMaxPathSum(root->right, ans);

    // leftPathMax and rightPathMax can be -ve, hence turning them into 0
    leftPathMax = max(leftPathMax, 0);
    rightPathMax = max(rightPathMax, 0);

    // max path sum with split
    ans = max(ans, root->val + leftPathMax + rightPathMax);

    // max path sum without split
    return root->val + max(leftPathMax, rightPathMax);
}

int maxPathSum(TreeNode *root)
{
    int ans = root->val;

    if (root == NULL)
        return 0;

    findMaxPathSum(root, ans);

    return ans;
}