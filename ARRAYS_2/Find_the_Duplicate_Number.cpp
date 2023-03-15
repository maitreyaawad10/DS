#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH
// int findDuplicate(vector<int>& nums) {
    // int arr[1000001] = {0};

    // for(int i = 0; i < nums.size(); ++i){
    //     arr[nums[i]]++;
    // }

    // for(int i = 1; i < nums.size(); ++i){
    //     if(arr[i] > 1){
    //         return i;
    //     }
    // }

    // return -1;
// }

// BETTER APPROCH
// int findDuplicate(vector<int>& nums) {
//     int ans = -1;

//     for(int i = 0; i < nums.size(); ++i){
//         int cur = abs(nums[i]);
//         if(nums[cur] < 0){
//             ans = cur;
//             break;
//         }
//         nums[cur] *= -1;
//     }

//     for (auto value : nums)
//         value = abs(value);

//     return ans;
// }

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int findDuplicate(vector<int>& nums) {
    int tortoise = nums[0];
    int hare = nums[0];

    do {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    tortoise = nums[0];

    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}