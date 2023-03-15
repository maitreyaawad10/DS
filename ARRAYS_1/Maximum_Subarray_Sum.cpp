#include <bits/stdc++.h>

using namespace std;

long long int maxSubArray(vector<int>& nums) {
    long long int sum = 0, maxSum = nums[0];

    for(int i = 0; i < nums.size(); ++i){
        sum += nums[i];
        maxSum = max(maxSum, sum);
        
        if(sum < 0) 
            sum = 0;
    }

    return maxSum;
}

int main(){

    return 0;
}