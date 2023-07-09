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
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return ans;

        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);

        return ans;
    }
};

// WITHOUT RECURSION, USING STACK
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (true)
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if (st.empty())
                    break;
                curr = st.top();
                ans.push_back(curr->val);
                st.pop();
                curr = curr->right;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}