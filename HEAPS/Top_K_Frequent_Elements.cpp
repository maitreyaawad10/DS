#include <bits/stdc++.h>

using namespace std;

// TC: O(N * LOG K)
// SC: O(N)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mp;

    for (auto value : nums)
    {
        mp[value]++;
    }

    // pair <count, key> for reverse mapping
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto value : mp)
    {
        pq.push({value.second, value.first});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;

    while (k--)
    {
        pair<int, int> heapTop = pq.top();
        pq.pop();

        ans.push_back(heapTop.second);
    }

    return ans;
}

// TC: O(N * LOG N)
// SC: O(N)
vector<int> topKFrequent(vector<int> &nums, int k)
{
    map<int, int> mp;

    for (auto value : nums)
    {
        mp[value]++;
    }

    vector<pair<int, int>> temp;
    for (auto value : mp)
    {
        temp.push_back({value.first, value.second});
    }

    sort(temp.begin(), temp.end(), [](pair<int, int> &a, pair<int, int> &b)
         {
             return a.second > b.second; // Reverse comparison logic
         });

    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        ans.push_back(temp[i].first);
    }

    return ans;
}