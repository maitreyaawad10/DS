#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH FOR GFG PROBLEM
// TC : O(MIN(M, N)) + N*LOGN + M*LOGM
/*
Input :
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two
non-decreasing arrays, we get,
0 1 2 3 5 6 7 8 9.
*/
void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// OPTIMAL APPROACH FOR LEETCODE PROBLEM
// TC : O(N), SC : O(1)
/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int last = m + n - 1;
    int i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] <= nums2[j])
        {
            nums1[last] = nums2[j];
            j--;
        }
        else
        {
            nums1[last] = nums1[i];
            i--;
        }

        last--;
    }

    while (j >= 0)
    {
        nums1[last] = nums2[j];
        last--;
        j--;
    }
}