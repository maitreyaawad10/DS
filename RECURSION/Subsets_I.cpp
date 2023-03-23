/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/
#include <bits/stdc++.h>

using namespace std;

// APPROACH 1
void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> output, int index){
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, ans, output, index + 1);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, ans, output, index + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(nums, ans, output, index);

    return ans;
}

// APPROACH 2
void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> ds, int index){
    ans.push_back(ds);

    for(int i = index; i < nums.size(); ++i){
        if(i != index && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(nums, ans, ds, i + 1);
        ds.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    sort(nums.begin(), nums.end());

    solve(nums, ans, output, index);

    return ans;
}