#include <bits/stdc++.h> 

using namespace std;

void findSubsetSum(vector<int> &nums, vector<int> &ans, int index, int sum){
    if(index >= nums.size()){
        ans.push_back(sum);
        return;
    }

    // excluding the current element from sum
    findSubsetSum(nums, ans, index + 1, sum);

    // including the current element in the sum
    int currentElement = nums[index];
    sum += currentElement;
    findSubsetSum(nums, ans, index + 1, sum);
}

vector<int> subsetSum(vector<int> &nums)
{
    int index = 0, sum = 0;
    vector<int> ans;

    findSubsetSum(nums, ans, index, sum);

    sort(ans.begin(), ans.end());

    return ans;
}