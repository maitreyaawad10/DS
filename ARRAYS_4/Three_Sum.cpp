#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH, TC : O(N^3), SC : O(3*k), k = no. of triplets
vector < vector < int >> threeSum(vector < int > & nums) {
    vector < vector < int >> ans;
    vector < int > temp;
    int i, j, k;

    for (i = 0; i < nums.size() - 2; i++) {
        for (j = i + 1; j < nums.size() - 1; j++) {
            for (k = j + 1; k < nums.size(); k++) {
                temp.clear();
                if (nums[i] + nums[j] + nums[k] == 0) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                }
                if (temp.size() != 0)
                    ans.push_back(temp);
            }
        }
    }

    return ans;
}

// OPTIMAL APPROACH, TC : O(N^2), SC : O(k), k = no. of triplets
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; ++i){
        if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
            int lo = i + 1, hi = n - 1, a = 0 - nums[i];

            while(lo < hi){
                if(nums[lo] + nums[hi] == a){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    ans.push_back(temp);

                    while(lo < hi && nums[lo] == nums[lo + 1])  lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1])  hi--;

                    lo++;
                    hi--;
                }

                else if(nums[lo] + nums[hi] < a)
                    lo++;
                
                else
                    hi--;
            }
        }
    }

    return ans;
}