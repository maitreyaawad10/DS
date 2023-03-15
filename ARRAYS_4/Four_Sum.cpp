#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH, TC : O(N^3Log(N)), SC : O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    
    set<vector<int>> sv;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            for(int k=j+1;k<n;k++)
            { 
                
                int x = (long long)target - 
                        (long long)nums[i]-
                        (long long)nums[j]-(long long)nums[k];
                
                    if(binary_search(nums.begin()+k+1,nums.end(),x)){
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(x);
                        sort(v.begin(),v.end());
                        sv.insert(v);
                    }
            }
        }
    }
    vector<vector<int>> res(sv.begin(),sv.end());
    return res;
}

// OPTIMAL APPROACH, TC : O(N^3), SC : O(1)
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 3; ++i){
        for(int j = i + 1; j < n - 2; ++j){
            int lo = j + 1, hi = n - 1;
            long long target_2 = (long long)target - (long long)nums[i] - (long long)nums[j];

            while(lo < hi){
                int two_sum = nums[lo] + nums[hi];
                if(two_sum < target_2)
                    lo++;
                
                else if(two_sum > target_2)
                    hi--;

                else{
                    vector<int> quadruple(4, 0);
                    quadruple[0] = nums[i];
                    quadruple[1] = nums[j];
                    quadruple[2] = nums[lo];
                    quadruple[3] = nums[hi];
                    ans.push_back(quadruple);

                    while(lo < hi && nums[lo] == quadruple[2])  lo++;
                    while(lo < hi && nums[hi] == quadruple[3])  hi--;
                }
            }

            while(j + 1 < n && nums[j + 1] == nums[j])  j++;
        }

        while(i + 1 < n && nums[i + 1] == nums[i])  i++;
    }

    return ans;
}