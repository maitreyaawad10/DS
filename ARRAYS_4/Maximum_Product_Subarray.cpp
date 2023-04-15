#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int maxProduct(vector<int>& nums) {
    int ans = nums[0], n = nums.size();
    int currMax = 1, currMin = 1;

    for(int i = 0; i < n; ++i){
        if(nums[i] == 0){
            ans = max(ans, nums[i]);
            currMax = 1, currMin = 1;
            continue;
        }
        
        int temp = currMax * nums[i];
        currMax = max(currMax * nums[i], max(currMin * nums[i], nums[i]));
        currMin = min(temp, min(currMin * nums[i], nums[i]));

        ans = max(ans, max(currMax, currMin));
    }

    return ans;
}