#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH, TC : O(N^2), SC : O(N)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int sum = 0;

    for(int i = 0; i < nums.size() - 1; ++i){
        for(int j = i + 1; j < nums.size(); ++j){
            sum = nums[i] + nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }

    return ans;
}

// OPTIMAL APPROACH, TC : O(N) or O(N*LOG(N)) DEPENDING UPON WHETHER WE USE MAP OR UNORDERED MAP, SC : O(N)
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    vector<int> ans;
    int sum = 0;

    for(int i = 0; i < nums.size(); ++i){
        sum = target - nums[i]; 

        if(mp.find(sum) != mp.end()){
            ans.push_back(mp[sum]);
            ans.push_back(i);
            break;
        }
        
        mp[nums[i]] = i;
        sum = target;
    }

    return ans;
}