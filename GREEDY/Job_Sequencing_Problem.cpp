#include <bits/stdc++.h> 

using namespace std;

// TC : O(N log N) + O(N*M)
// SC : O(M)
bool cmp(vector<int> v1, vector<int> v2){
    return (v1[1] > v2[1]);
}

int jobScheduling(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), cmp);
        
    int maxi = arr[0][0];
    
    for(int i = 0; i < arr.size(); ++i)
        maxi = max(maxi, arr[i][0]);
    
    int slot[maxi + 1];
    
    for(int i = 1; i <= maxi; ++i)
        slot[i] = -1;
    
    int profit = 0;
    
    for(int i = 0; i < arr.size(); ++i){
        for(int j = arr[i][0]; j > 0; --j){
            if(slot[j] == -1){
                slot[j] = i;
                profit += arr[i][1];
                break;
            }
        }
    }

    return profit;
}
