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

// GFG & CODESTUDIO
// TC : O(N * logN)
// SC : O(N)
vector<int> verticalOrder(TreeNode *root)
{
    map<int, vector<int>> nodes;
    queue<pair<TreeNode *, int>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<TreeNode *, int> temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;
        int horiDistance = temp.second;

        nodes[horiDistance].push_back(frontNode->val);

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, horiDistance - 1));

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, horiDistance + 1));
    }

    for (auto mainMapValues : nodes)
    {
        for (auto value : mainMapValues.second)
            ans.push_back(value);
    }

    return ans;
}

// LEETCODE
// TC : O(N * logN * logN * logN)
// SC : O(N)
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<TreeNode *, pair<int, int>> temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;

        int horiDistance = temp.second.first;
        int level = temp.second.second;

        nodes[horiDistance][level].insert(frontNode->val);

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, make_pair(horiDistance - 1, level + 1)));

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, make_pair(horiDistance + 1, level + 1)));
    }

    for (auto mainMapValues : nodes)
    {
        vector<int> vec;
        for (auto secondMapValues : mainMapValues.second)
        {
            for (auto setValues : secondMapValues.second)
            {
                vec.push_back(setValues);
            }
        }
        ans.push_back(vec);
    }

    return ans;
}