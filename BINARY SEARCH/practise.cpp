#include <bits/stdc++.h>

using namespace std;

int lesserThanEqualToMid(vector<int> row, int mid){
    int s = 0, e = row.size() - 1;

    while(s <= e){
        int m = s + (e - s) / 2;

        if(row[m] <= mid)
            s = m + 1;
        
        else
            e = m - 1;
    }

    return s;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int s = 1, e = 1e9;

    while(s <= e){
        int mid = s + (e - s) / 2;

        int cnt = 0;
        
        for(int i = 0; i < n; ++i)
            cnt += lesserThanEqualToMid(matrix[i], mid);
        
        if(cnt <= (n*m / 2))
            s = mid + 1;

        else
            e = mid - 1;
    }

    return s;
}

int main(){
    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;

    vector<int> nums1, nums2;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        nums1.push_back(x);
    }

    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    // cout << kthElement(nums1, nums2, nums1.size(), nums2.size(), k) << endl;

    return 0;
}