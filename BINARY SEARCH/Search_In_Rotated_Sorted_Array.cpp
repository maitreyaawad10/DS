#include <bits/stdc++.h>

using namespace std;

int getPivot(vector<int>& nums, int n){
    int s = 0, e = n - 1;
    
    if(nums[0] <= nums[n - 1])
        return 0;

    while(s < e){
        int mid = s + ((e - s) / 2);

        if(nums[mid] >= nums[0])
            s = mid + 1;
        
        else
            e = mid;
    }
    
    return s;
}

int binarySearch(vector<int>& nums, int target, int s, int e){
    int low = s, high = e;

    if(nums.size() == 1 && nums[0] == target)
        return 0;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(nums[mid] == target)
            return mid;
        
        if(nums[mid] < target)
            low = mid + 1;
        
        else
            high = mid - 1;
    }

    return -1;
}


int search(vector<int>& nums, int target) {
    int n = nums.size();
    int pivot = getPivot(nums, n);

    if(target <= nums[n - 1] && target >= nums[pivot])
        return binarySearch(nums, target, pivot, n - 1);

    else
        return binarySearch(nums, target, 0, pivot - 1);
    
}

int main(){
    int n = 1, k = 1;
    vector<int> arr = {1};

    cout << search(arr, k) << endl;

    return 0;
}