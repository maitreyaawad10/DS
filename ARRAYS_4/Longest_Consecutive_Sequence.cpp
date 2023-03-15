#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N) + O(N) + O(N), SC : O(N)
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;

    for(int value : nums)
        st.insert(value);

    int largestStreak = 0;

    for(int value : nums){
        if(!st.count(value - 1)){
            int currentStreak = 1, currentValue = value;
            
            while(st.count(currentValue + 1)){
                currentStreak++;
                currentValue++;
            }

            largestStreak = max(largestStreak, currentStreak);
        }
    }

    return largestStreak;
}