#include <bits/stdc++.h>

using namespace std;

#define ll long long

// 1 7 3 6 5 6
void solve(){
    int n;
    cin >> n;
    
    vector<int> nums;

    for(int i = 0; i < n; ++i){
        int y;
        cin >> y;
        nums.push_back(y);
    }

    for(int x = 0; x < n; ++x){
        int suml = 0, sumr = 0;

        for(int i = 0; i < x; ++i){
            suml += nums[i];
        }

        for(int j = n - 1; j > x; --j){
            sumr += nums[j];
        }
        
        if(suml == sumr){
            cout << "Pivot is : " << x << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main(){
    solve();

    return 0;
}