#include <bits/stdc++.h>

using namespace std;

// OPTIMIZED APPROACH
// TIME COMLPEXITY : O(N),
// SPACE COMPLEXITY : O(1)
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), k, x;

    for(k = n - 2; k >= 0; --k){
        if(nums[k] < nums[k + 1])
            break;
    }

    if(k < 0){
        reverse(nums.begin(), nums.end());
    }
    else{
        for(x = n - 1; x > k; --x){
            if(nums[x] > nums[k])
                break;
        }

        swap(nums[k], nums[x]);

        reverse(nums.begin() + k + 1, nums.end());
    }
}







// UNOPTIMIZED APPROACH
// void allPermutations(vector<int> &nums, set<vector<int>> &ans, int index){

//     if(index == nums.size()){
//         ans.insert(nums);
//         return;
//     }

//     for(int i = index; i < nums.size(); ++i){
//         swap(nums[index], nums[i]);
//         allPermutations(nums, ans, index + 1);
//         swap(nums[index], nums[i]);
//     }
// }

// void changeVector(vector<int> temp, vector<int>& nums){
//     for(int i = 0; i < temp.size(); ++i)
//         nums[i] = temp[i];
// }

// void nextPermutation(vector<int>& nums) {
//     set<vector<int>> ans;
    
//     allPermutations(nums, ans, 0);

//     int i = 0;
//     for(auto it = ans.begin(); it != ans.end(); ++it, ++i){

//         if((*it) == nums && i != ans.size() - 1){
//             changeVector(*(++it), nums);
//             break;
//         }
//         else if((*it) == nums && i == ans.size() - 1){
//             changeVector(*(ans.begin()), nums);
//             break;
//         }
//     }
// }