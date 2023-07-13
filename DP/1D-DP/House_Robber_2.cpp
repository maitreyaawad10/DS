#include <bits/stdc++.h>

using namespace std;

// SAME CODE AS IN MAXIMUM SUM OF NON ADJACENT ELEMENTS
// APPROACH 4: OPTIMAL, DP, (space optimized)
// TC: O(N)
// SC: O(1)
long long int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    long long int prev1 = nums[0], prev2 = nums[0];

    for (long long int i = 1; i < n; ++i)
    {
        long long int pickCurrElement = nums[i];

        if (i > 1)
            pickCurrElement += prev2;

        long long int notPickCurrElement = 0 + prev1;

        long long int curr = max(pickCurrElement, notPickCurrElement);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    vector<int> first, last;
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    for (int i = 0; i < n; ++i)
    {
        if (i != n - 1)
            first.push_back(valueInHouse[i]);
        if (i != 0)
            last.push_back(valueInHouse[i]);
    }

    long long int leftAns = maximumNonAdjacentSum(first);
    long long int rightAns = maximumNonAdjacentSum(last);

    return max(leftAns, rightAns);
}