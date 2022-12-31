#include <bits/stdc++.h>

using namespace std;

// USING TWO METHODS
// METHOD 1 : WITHOUT USING LOWER BOUND AND UPPER BOUND INBUILT FUNCTIONS

int firstOccurence(vector<int>& arr, int n, int k){
    int start = 0, end = n - 1;
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        if(arr[mid] == k){
            ans = mid;
            end = mid - 1;
        }

        else if(arr[mid] < k){
            start = mid + 1;
        }

        else{
            end = mid - 1;
        }
    }

    return ans;
}

int lastOccurence(vector<int>& arr, int n, int k){
    int start = 0, end = n - 1;
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        if(arr[mid] == k){
            ans = mid;
            start = mid + 1;
        }

        else if(arr[mid] < k){
            start = mid + 1;
        }

        else{
            end = mid - 1;
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> p;
    p.first = firstOccurence(arr, n, k);
    p.second = lastOccurence(arr, n, k);

    return p;
}

// METHOD 2 : WITH USING LOWER BOUND AND UPPER BOUND INBUILT FUNCTIONS

vector<int> searchRange(vector<int>& nums, int target) {
    bool index = binary_search(nums.begin(), nums.end(), target);

    auto first = lower_bound(nums.begin(), nums.end(), target);
    auto last = upper_bound(nums.begin(), nums.end(), target);

    vector<int> ans;

    if(first != nums.end() && index == true){
        ans.push_back(first - nums.begin());
        ans.push_back((last- nums.begin()) - 1);
    }
    else if(index == false){
        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;
}