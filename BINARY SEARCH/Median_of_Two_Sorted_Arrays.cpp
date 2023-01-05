#include <bits/stdc++.h>

using namespace std;

// arr1 = 7 12 14 15
// arr2 = 1 2 3 4 9 11

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if(nums2.size() < nums1.size())
        return findMedianSortedArrays(nums2, nums1);

    int n = nums1.size() + nums2.size();
    int left_half_size = (n + 1) / 2;
    
    int s = 0, e = nums1.size();

    while(s <= e){
        int cut1 = s + ((e - s) / 2);
        int cut2 = left_half_size - cut1;

        int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int r1 = cut1 == nums1.size() ? INT_MAX : nums1[cut1];
        int r2 = cut2 == nums2.size() ? INT_MAX : nums2[cut2];

        if(l1 > r2)
            e = cut1 - 1;

        else if(l2 > r1)
            s = cut1 + 1;
        
        else{
            if(n % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }
    }

    return 0.0;
}

int main(){
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};

    // for(auto value : nums1)
    //     cout << value << " ";
    // cout << endl;

    // for(auto value : nums2)
    //     cout << value << " ";
    // cout << endl;

    double ans = findMedianSortedArrays(nums1, nums2);

    cout << ans << endl;

    return 0;
}