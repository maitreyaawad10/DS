#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arr;

    for(int i = 0; i < n; ++i){
        vector<int> v1;
        for(int j = 0; j < m; ++j){
            int x;
            cin >> x;
            v1.push_back(x);    
        }
        arr.push_back(v1);
    }    

    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++j){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }    
    // cout << endl;

    cout << arr.size() << endl;
}

int main(){
    solve();

    return 0;
}