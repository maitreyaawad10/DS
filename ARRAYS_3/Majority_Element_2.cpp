#include <bits/stdc++.h> 

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
// MOORE'S VOTING ALGORITHM
vector<int> majorityElement(vector<int>& nums) {
    int sz = nums.size();
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < sz; ++i){
        if(nums[i] == num1)
            cnt1++;
        else if(nums[i] == num2)
            cnt2++;
        else if(cnt1 == 0){
            num1 = nums[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0){
            num2 = nums[i];
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }

    int c1 = 0, c2 = 0;
    for(int i = 0; i < sz; ++i){
        if(nums[i] == num1)
            c1++;
        else if(nums[i] == num2)
            c2++;
    }   

    vector<int> ans;

    if(c1 > sz / 3)
        ans.push_back(num1);
    if(c2 > sz / 3)
        ans.push_back(num2);

    return ans;
}
