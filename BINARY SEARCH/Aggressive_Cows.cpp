#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &stalls, int k, int dist){
    int cowCount = 1, lastPos = stalls[0];

    for(int i = 0; i < stalls.size(); ++i){
        if((stalls[i] - lastPos) >= dist){
            cowCount++;
            
            if(cowCount == k)
                return true;
            
            lastPos = stalls[i];
        }
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){    
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;

    while(s <= e){
        int m = s + ((e - s) / 2);

        if(isPossible(stalls, k, m)){
            ans = m;
            s = m + 1;
        }
        else{
            e = m - 1;
        }
    }

    return ans;
}