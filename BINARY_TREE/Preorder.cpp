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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return ans;
        }

        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        return ans;
    }
};

// WITHOUT RECURSION, USING TWO STACKS
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        TreeNode *curr = root;

        if (root == NULL)
            return ans;

        st1.push(curr);

        while (!st1.empty())
        {
            curr = st1.top();
            st2.push(curr);
            st1.pop();
            if ((curr->left) != NULL)
                st1.push(curr->left);
            if ((curr->right) != NULL)
                st1.push(curr->right);
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}