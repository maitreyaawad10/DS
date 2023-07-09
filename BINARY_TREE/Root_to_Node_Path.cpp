#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

// TC : O(N)
// SC : O(HEIGHT OF TREE)
TreeNode<int> *findPath(TreeNode<int> *root, int x, vector<int> &path)
{
    if (root == NULL)
        return NULL;

    if (root->data == x)
    {
        path.push_back(root->data);
        return root;
    }

    path.push_back(root->data);

    TreeNode<int> *leftAns = findPath(root->left, x, path);
    TreeNode<int> *rightAns = findPath(root->right, x, path);

    if (leftAns == NULL && rightAns == NULL)
    {
        path.pop_back();
        return NULL;
    }
    else if (leftAns != NULL)
        return leftAns;
    else
        return rightAns;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> path;

    findPath(root, x, path);

    return path;
}