#include <bits/stdc++.h>

using namespace std;

#define ll long long

// 4 5 6 7 0 1 2
void solve(){
    int n;
    cin >> n;
    
    vector<int> nums;

    for(int i = 0; i < n; ++i){
        int y;
        cin >> y;
        nums.push_back(y);
    }

    int s = 0, e = n - 1;

    while(s < e){
        int mid = s + ((e - s) / 2);

        if(nums[mid] >= nums[0])
            s = mid + 1;
        else
            e = mid;
    }
    
    cout << nums[s] << endl;
}

int main(){
    solve();

    return 0;
}