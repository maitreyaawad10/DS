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

// TC: O(N), SC: O(H)
class BSTIterator
{
private:
    stack<TreeNode *> st;

public:
    void pushLeft(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode *top = st.top();
        st.pop();
        if (top->right != NULL)
            pushLeft(top->right);
        return top->val;
    }

    bool hasNext()
    {
        if (!st.empty())
            return true;

        return false;
    }
};