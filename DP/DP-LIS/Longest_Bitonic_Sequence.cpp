#include <bits/stdc++.h>

using namespace std;

// APPROACH 1: DP, TABULATION
// TC: O(N * N)
// SC: O(N)
int longestBitonicSubsequence(vector<int> &arr, int n)
{
    vector<int> lis1(n, 1);
    vector<int> lis2(n, 1);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                lis1[i] = max(lis1[i], lis1[j] + 1);
            }
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j >= i; --j)
        {
            if (arr[i] > arr[j])
            {
                lis2[i] = max(lis2[i], lis2[j] + 1);
            }
        }
    }

    int ans = 1;

    for (int i = 0; i < n; ++i)
    {
        int sum = lis1[i] + lis2[i] - 1;
        ans = max(ans, sum);
    }

    return ans;
}
