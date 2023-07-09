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
TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int &postOrderIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &mp)
{
    // base case
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int currElement = postorder[postOrderIndex--];
    TreeNode *root = new TreeNode(currElement);
    int positionInInorder = mp[currElement];

    root->right = solve(postorder, inorder, postOrderIndex, positionInInorder + 1, inOrderEnd, size, mp);
    root->left = solve(postorder, inorder, postOrderIndex, inOrderStart, positionInInorder - 1, size, mp);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int size = inorder.size();

    int postOrderIndex = size - 1;
    int inOrderStart = 0, inOrderEnd = size - 1;

    unordered_map<int, int> mp;

    for (int i = 0; i < size; ++i)
        mp[inorder[i]] = i;

    TreeNode *root = solve(postorder, inorder, postOrderIndex, inOrderStart, inOrderEnd, size, mp);

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

TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int &postOrderIndex, int inOrderStart, int inOrderEnd, int size)
{
    // base case
    if (postOrderIndex < 0 || inOrderStart > inOrderEnd)
        return NULL;

    int currElement = postorder[postOrderIndex--];
    TreeNode *root = new TreeNode(currElement);
    int positionInInorder = findPosition(inorder, inOrderStart, inOrderEnd, currElement);

    root->right = solve(postorder, inorder, postOrderIndex, positionInInorder + 1, inOrderEnd, size);
    root->left = solve(postorder, inorder, postOrderIndex, inOrderStart, positionInInorder - 1, size);

    return root;
}

TreeNode *buildTree(vector<int> &postorder, vector<int> &inorder)
{
    int size = inorder.size();

    int postOrderIndex = size - 1;
    int inOrderStart = 0, inOrderEnd = size - 1;

    TreeNode *root = solve(postorder, inorder, postOrderIndex, inOrderStart, inOrderEnd, size);

    return root;
}