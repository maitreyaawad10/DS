#include <bits/stdc++.h>

using namespace std;

// BRUTE FORCE APPROACH, TC : O(N^2), SC : O(N)
int lengthOfLongestSubstring(string str) {
    if(str.size()==0)
        return 0;

    int maxans = INT_MIN;

    for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
    {
        unordered_set < int > set;
        for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }
            set.insert(str[j]);
        }
    }
    return maxans;
}

// OPTIMAL APPROACH, TC : O(N), SC : O(N)
int lengthOfLongestSubstring(string s) {
    vector<int> mp(256, -1); // since string contains 256 types of different characters
    int maxLen = 0, lo = 0, hi = 0;
    int n = s.length();

    while(hi < n){
        if(mp[s[hi]] != -1)
            lo = max(lo, mp[s[hi]] + 1);

        mp[s[hi]] = hi;
        maxLen = max(maxLen, (hi - lo) + 1);
        hi++;
    }

    return maxLen;
}