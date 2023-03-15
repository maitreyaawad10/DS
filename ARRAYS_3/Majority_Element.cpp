#include <bits/stdc++.h> 

using namespace std;

// BRUTE FORCE, TC : O(N), SC : O(N * LOG(N))
int majorityElement(vector<int>& nums) {
    map<int, int> mp;
    int major = INT_MIN, n = nums.size();

    for(int i = 0; i < n; ++i)
        mp[nums[i]]++;

    int x = n / 2, ans = -1;
    for(auto value : mp){
        if (value.second > x && value.second > major){
            ans = value.first;
            major = value.second;
        }
    }
        
    return ans;
}

// OPTIMAL APPROACH, TC : O(N)X SC : O(1)
// MOORE'S VOTING ALGORITHM
int majorityElement(vector<int>& nums) {
    int count = 0, element = 0;

    for(int value : nums){
        if(count == 0)
            element = value;
        
        if(value == element)
            count += 1;
        else
            count -= 1;
    }

    return element;
}
