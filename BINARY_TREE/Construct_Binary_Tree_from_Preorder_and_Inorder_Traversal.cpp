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
// WHEN TREE CONTAINS UNIQUE ELEMENTS USE UNORDERED_MAP
TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preOrderIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &mp)
{
    // base case
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
        return NULL;

    int currElement = preorder[preOrderIndex++];
    TreeNode *root = new TreeNode(currElement);
    int positionInInorder = mp[currElement];
    // int positionInInorder = findPosition(inorder, inOrderStart, inOrderEnd, currElement);

    root->left = solve(preorder, inorder, preOrderIndex, inOrderStart, positionInInorder - 1, size, mp);
    root->right = solve(preorder, inorder, preOrderIndex, positionInInorder + 1, inOrderEnd, size, mp);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();

    int preOrderIndex = 0;
    int inOrderStart = 0, inOrderEnd = size - 1;

    unordered_map<int, int> mp;

    for (int i = 0; i < size; ++i)
        mp[inorder[i]] = i;

    TreeNode *root = solve(preorder, inorder, preOrderIndex, inOrderStart, inOrderEnd, size, mp);

    return root;
}

// TC : O(N), SC : O(N)
// WHEN TREE CONTAINS DUPLICATE ELEMENTS WRITE A FUNCTION TO FIND THE INDEX
int findPosition(vector<int> &inorder, int inOrderStart, int inOrderEnd, int element)
{
    for (int i = inOrderStart; i <= inOrderEnd; ++i)
    {
        if (inorder[i] == element)
            return i;
    }

    return -1;
}

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &preOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (preOrderIndex >= size || inOrderStart > inOrderEnd)
        return NULL;

    int currElement = preorder[preOrderIndex++];
    TreeNode *root = new TreeNode(currElement);
    int positionInInorder = findPosition(inorder, inOrderStart, inOrderEnd, currElement);

    root->left = solve(preorder, inorder, preOrderIndex, inOrderStart, positionInInorder - 1, size);
    root->right = solve(preorder, inorder, preOrderIndex, positionInInorder + 1, inOrderEnd, size);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();

    int preOrderIndex = 0;
    int inOrderStart = 0, inOrderEnd = size - 1;

    TreeNode *root = solve(preorder, inorder, preOrderIndex, inOrderStart, inOrderEnd, size);

    return root;
}