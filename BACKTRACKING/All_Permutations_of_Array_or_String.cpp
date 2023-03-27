#include <bits/stdc++.h> 

using namespace std;

// ALL PERMUTATIONS OF ARRAY
void findPermutations(vector<int>& nums, vector<vector<int>> &ans, int index){
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i = index; i < nums.size(); ++i){
        swap(nums[i], nums[index]);
        findPermutations(nums, ans, index + 1);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    
    int index = 0;

    findPermutations(nums, ans, index);

    return ans;
}

// ALL PERMUTATIONS OF STRING
void findPermutations(string &s, vector<string> &ans, int index){
    if(index >= s.length()){
        ans.push_back(s);
        return;
    }

    for(int i = index; i < s.size(); ++i){
        swap(s[i], s[index]);
        findPermutations(s, ans, index + 1);
        swap(s[i], s[index]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    int index = 0;

    findPermutations(s, ans, index);

    return ans;
}