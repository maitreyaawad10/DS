#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// TC : O(N)
// SC : O(H)
pair<int, int> solve(Node *root)
{
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> result;
    // including the nodes at current level
    result.first = root->data + leftAns.second + rightAns.second;

    // excluding the nodes at current level
    result.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return result;
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);

    return max(ans.first, ans.second);
}