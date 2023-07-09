#include <bits/stdc++.h>

using namespace std;

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

vector<vector<int>> getTreeTraversal(BinaryTreeNode *root)
{
    vector<int> inOrder, preOrder, postOrder;
    stack<pair<BinaryTreeNode *, int>> st;
    st.push({root, 1});

    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    while (!st.empty())
    {
        BinaryTreeNode *curr = st.top().first;
        int num = st.top().second;

        st.pop();

        if (num == 1)
        {
            preOrder.push_back(curr->data);
            num++;
            st.push({curr, num});

            if (curr->left != NULL)
                st.push({curr->left, 1});
        }
        else if (num == 2)
        {
            inOrder.push_back(curr->data);
            num++;
            st.push({curr, num});

            if (curr->right != NULL)
                st.push({curr->right, 1});
        }
        else
        {
            postOrder.push_back(curr->data);
        }
    }

    ans.push_back(inOrder);
    ans.push_back(preOrder);
    ans.push_back(postOrder);

    return ans;
}