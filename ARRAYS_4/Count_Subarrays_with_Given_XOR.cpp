#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(N), SC : O(N)
int subarraysXor(vector<int> &arr, int x)
{
    int xxor = 0;
    int cnt = 0;
    int n = arr.size();
    
    unordered_map<int, int> mp;

    for(int i = 0; i < n; ++i){
        xxor ^= arr[i];

        if(xxor == x)
            cnt++;
        
        if(mp.find(xxor ^ x) != mp.end())
            cnt += mp[xxor ^ x];

        mp[xxor]++;
    }

    return cnt;
}