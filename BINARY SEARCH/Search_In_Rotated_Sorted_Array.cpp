#include <bits/stdc++.h>

using namespace std;

int getPivot(vector<int>& arr, int n){
    int s = 0, e = n - 1;

    while(s < e){
        int mid = s + ((e - s) / 2);

        if(arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }

    return s;   // return e - will also work
}

int binarysearch(vector<int>& arr, int s, int e, int k) {
    int low = s, high = e;

    while(low <= high){
        int mid = low + ((high - low) / 2);

        if(arr[mid] == k)
            return mid;

        if(arr[mid] < k)
            low = mid + 1;

        else
            high = mid;
    }

    return -1;
}

int findPosition(vector<int>& arr, int n, int k)
{   
    int n, k = 2;
    vector<int> arr;
    
    int pivot = getPivot(arr, n);

    if(k >= pivot && k <= arr[n - 1])
        return binarysearch(arr, pivot, n - 1, k);
    else    
        return binarysearch(arr, 0, pivot - 1, k);
}

int main(){


    return 0;
}