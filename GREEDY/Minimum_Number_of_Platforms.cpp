#include <bits/stdc++.h> 

using namespace std;

// TC : O(2*N LOG(N) + 2N)
// SC : O(1)

int calculateMinPatforms(int arr[], int dep[], int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int platforms = 1, ans = 1;
    int i = 1, j = 0;
    
    while(i < n && j < n){
        if(arr[i] <= dep[j]){
            platforms++;
            i++;
        }
        else {
            platforms--;
            j++;
        }
        
        ans = max(ans, platforms);
    }
    
    return ans;
}