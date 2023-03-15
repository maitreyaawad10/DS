#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(N)
int LongestSubsetWithZeroSum(vector < int > nums) {
    unordered_map<int, int> mp;
    
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < nums.size(); ++i){
        sum += nums[i];

        if(sum == 0)
            maxLen = i + 1;

        else if(mp.find(sum) != mp.end()) 
            maxLen = max(maxLen, i - mp[sum]);

        else
            mp[sum] = i;
    }

  return maxLen;
}