#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int s = 0, e = nums.size() - 2;

    while(s <= e){
        int mid = s + ((e - s) / 2);

        if(nums[mid] == nums[mid ^ 1])
            s = mid + 1;
        else
            e = mid - 1;

        // Same as above condition
        // if(mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 != 0 && nums[mid] == nums[mid - 1])
        //     s = mid + 1;
        // else
        //     e = mid - 1;
    }

    return nums[s];
}

int main(){
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    
    int ans = singleNonDuplicate(nums);

    cout << ans << endl; 

    return 0;
}