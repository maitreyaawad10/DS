#include <bits/stdc++.h>

using namespace std;

// TC: O(N), SC: O(1)
int maxProfit(vector<int> &prices)
{
    int profit = 0, currMin = 1e9, n = prices.size();

    for (int i = 0; i < n; ++i)
    {
        currMin = min(currMin, prices[i]);

        if (prices[i] > currMin)
            profit = max(profit, prices[i] - currMin);
    }

    return profit;
}