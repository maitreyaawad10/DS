/*
Given an integer array nums that may contain duplicates, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include <bits/stdc++.h>

using namespace std;

void findSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds, int index){
    ans.push_back(ds);

    for(int i = index; i < nums.size(); ++i){
        if(i != index && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubsets(nums, ans, ds, i + 1);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());

    findSubsets(nums, ans, ds, 0);

    return ans;
}