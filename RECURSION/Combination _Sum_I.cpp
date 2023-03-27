#include <bits/stdc++.h> 

using namespace std;

void findCombinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int> &ds, int index, int target){
    if(index == candidates.size()){
        if(target == 0)
            ans.push_back(ds);
        return;
    }

    // include the current element
    if(candidates[index] <= target){
        ds.push_back(candidates[index]);
        findCombinations(candidates, ans, ds, index, target - candidates[index]);
        ds.pop_back();
    }

    // exclude the current element
    findCombinations(candidates, ans, ds, index + 1, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    
    findCombinations(candidates, ans, ds, index, target);

    return ans;
}