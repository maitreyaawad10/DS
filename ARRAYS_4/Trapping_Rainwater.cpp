#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int trap(vector<int>& height) {
    int n = height.size();

    int maxL = height[0];
    int maxR = height[n - 1];

    int left = 0;
    int right = n - 1;

    int trappedWater = 0;

    while (left < right) {
        if (maxL <= maxR) {
            int add = maxL - height[left];
            left++;

            trappedWater += (add < 0 ? 0 : add);

            maxL = max(maxL, height[left]);
        } else {
            int add = maxR - height[right];
            right--;

            trappedWater += (add < 0 ? 0 : add);

            maxR = max(maxR, height[right]);
        }
    }

    return trappedWater;
}

// BETTER APPROACH, TC : O(N), SC : O(N)
int trap(vector<int>& height) {
    int n = height.size();

    int prefix[n];
    int suffix[n];

    int max_ele = height[0];
    for(int i = 0; i < n; ++i){
        max_ele = max(max_ele, height[i]);
        prefix[i] = max_ele;
    }

    max_ele = height[n - 1];
    for(int j = n - 1; j >= 0; --j){
        max_ele = max(max_ele, height[j]);
        suffix[j] = max_ele;
    }

    int trappedWater = 0;

    for(int i = 0; i < n; ++i){
        trappedWater += (min(prefix[i], suffix[i]) - height[i]);
    }

    return trappedWater;
}

// OPTIMAL APPROACH, TC : O(N), SC : O(1)
int trap(vector < int > & height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxLeft) 
                maxLeft = height[left];
            else 
                res += maxLeft - height[left];
            
            left++;
        } 
        
        else {
            if (height[right] >= maxRight) 
                maxRight = height[right];
            else 
                res += maxRight - height[right];

            right--;
        }
    }

    return res;
}
