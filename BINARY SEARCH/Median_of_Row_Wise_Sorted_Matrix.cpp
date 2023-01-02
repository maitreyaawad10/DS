#include <bits/stdc++.h>

using namespace std;

#define ll long long

// TIME COMPLEXITY => log(2^32) * N * log(M) => 32 * N * log(M)

int countLesserThanEqual(vector<int> &row, int mid){
    int s = 0, e = row.size() - 1;

    while(s <= e){
        int md = s + ((e - s) / 2);

        if(row[md] > mid)
            e = md - 1;
        else
            s = md + 1;
    }
    
    return s;
}

int binarySearch(vector<vector<int> > &arr, int n, int m){
    int s = 1, e = 1e9;

    while(s <= e){
        int mid = s + ((e - s) / 2);
        int count = 0;

        for(int i = 0; i < n; ++i)
            count += countLesserThanEqual(arr[i], mid);

        if(count <= ((n * m) / 2))
            s = mid + 1;
        else    
            e = mid - 1;
    }

    return s;
}

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

    cout << binarySearch(arr, n, m) << endl;
}

int main(){
    solve();

    return 0;
}