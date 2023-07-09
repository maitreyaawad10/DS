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

// WITH RECURSION
class Solution
{
    vector<int> ans;

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return ans;
        }

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.push_back(root->val);

        return ans;
    }
};

// WITHOUT RECURSION, USING STACK
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st1;
        TreeNode *curr = root;

        if (root == NULL)
            return ans;

        st1.push(curr);

        while (!st1.empty())
        {
            curr = st1.top();
            ans.push_back(curr->val);
            st1.pop();
            if ((curr->left) != NULL)
                st1.push(curr->left);
            if ((curr->right) != NULL)
                st1.push(curr->right);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{

    return 0;
}