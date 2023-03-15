#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    // BRUTE FORCE APPROACH
    // int i = 0, j = 0;

    // vector<int> v;

    // while(i < m && j < n){
    //     if(nums1[i] <= nums2[j]){
    //         v.push_back(nums1[i]);
    //         i++;
    //     }
    //     else{
    //         v.push_back(nums2[j]);
    //         j++;
    //     }
    // }

    // if(i < m){
    //     while(i < m){
    //         v.push_back(nums1[i]);
    //         i++;
    //     }
    // }
    // else{
    //     while(j < n){
    //         v.push_back(nums2[j]);
    //         j++;
    //     }
    // }

    // for(int i = 0; i < v.size(); ++i){
    //     nums1[i] = v[i];
    // }

    // OPTIMAL APPROACH
    int i = 0, j = 0, x = 0;

    while((x < m + n) && i < m && j < n){
        if(nums1[i] <= nums2[j]){
            i++;
        }
        else{
            swap(nums1[i], nums2[j]);
            sort(nums2.begin(), nums2.end());
            i++;
        }
        x++;
    }

    while(j < n){
        nums1[x] = nums2[j];
        j++;
        x++;
    }
}

int main(){

    solve();

    return 0;
}