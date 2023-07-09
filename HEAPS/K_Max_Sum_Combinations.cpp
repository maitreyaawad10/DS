#include <bits/stdc++.h>

using namespace std;

// TC: O(N * LOG N)
// SC: O(N)
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    set<pair<int, int>> taken;
    vector<int> ans;

    maxHeap.push({(a[0] + b[0]), {0, 0}});

    for (int i = 0; i < k; ++i)
    {
        pair<int, pair<int, int>> qTop = maxHeap.top();
        maxHeap.pop();

        ans.push_back(qTop.first);

        int aNextIndex = qTop.second.first + 1;
        int bNextIndex = qTop.second.second + 1;

        if (bNextIndex < n && taken.find({aNextIndex - 1, bNextIndex}) == taken.end())
        {
            maxHeap.push({(a[aNextIndex - 1] + b[bNextIndex]), {aNextIndex - 1, bNextIndex}});
            taken.insert({aNextIndex - 1, bNextIndex});
        }
        if (aNextIndex < n && taken.find({aNextIndex, bNextIndex - 1}) == taken.end())
        {
            maxHeap.push({(a[aNextIndex] + b[bNextIndex - 1]), {aNextIndex, bNextIndex - 1}});
            taken.insert({aNextIndex, bNextIndex - 1});
        }
    }

    return ans;
}