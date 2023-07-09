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
    stack<TreeNode *> asc;
    stack<TreeNode *> desc;

    void pushAsc(TreeNode *node)
    {
        while (node != NULL)
        {
            asc.push(node);
            node = node->left;
        }
    }

    void pushDesc(TreeNode *node)
    {
        while (node != NULL)
        {
            desc.push(node);
            node = node->right;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAsc(root);
        pushDesc(root);
    }

    int next()
    {
        TreeNode *top = asc.top();
        asc.pop();

        if (top->right != NULL)
            pushAsc(top->right);

        return top->val;
    }

    int before()
    {
        TreeNode *top = desc.top();
        desc.pop();

        if (top->left != NULL)
            pushDesc(top->left);

        return top->val;
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator s(root);

        int i = s.next();
        int j = s.before();

        while (i < j)
        {
            if (i + j == k)
                return true;

            else if (i + j < k)
                i = s.next();

            else
                j = s.before();
        }

        return false;
    }
};