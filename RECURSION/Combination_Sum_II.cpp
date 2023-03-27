#include <bits/stdc++.h> 

using namespace std;

void findCombinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int> &ds, int index, int target){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i = index; i < candidates.size(); ++i){
        if(i > index && candidates[i] == candidates[i - 1])
            continue;
        if(candidates[i] > target)
            break;

        ds.push_back(candidates[i]);
        findCombinations(candidates, ans, ds, i + 1, target - candidates[i]);
        ds.pop_back();
    }
}      

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    int index = 0;
    sort(candidates.begin(), candidates.end());

    findCombinations(candidates, ans, ds, index, target);

    return ans;
}