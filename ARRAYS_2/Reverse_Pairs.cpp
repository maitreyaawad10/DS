#include <bits/stdc++.h> 

using namespace std;
#define ll long long

void merge(vector<int>& arr, ll s, ll mid, ll e, ll &reversePairs){
    ll j = mid + 1;
    for(ll i = s; i <= mid; ++i){
        while(j <= e && (arr[i] > 2LL*arr[j]))
            j++;
        reversePairs += (j - (mid + 1));
    }

    vector<int> temp;
    ll leftArrayIndex = s, rightArrayIndex = mid + 1;
    
    while(leftArrayIndex <= mid && rightArrayIndex <= e){
        if(arr[leftArrayIndex] > arr[rightArrayIndex])
            temp.push_back(arr[rightArrayIndex++]);  
        else
            temp.push_back(arr[leftArrayIndex++]);
    }

    while(leftArrayIndex <= mid)
        temp.push_back(arr[leftArrayIndex++]);

    while(rightArrayIndex <= e)
        temp.push_back(arr[rightArrayIndex++]);

    for(int i = s; i <= e; ++i)
        arr[i] = temp[i - s];
}

void mergeSort(vector<int>& arr, ll s, ll e, ll &reversePairs){
    if(s >= e)
        return;

    ll mid = s + (e - s) / 2;

    mergeSort(arr, s, mid, reversePairs);
    mergeSort(arr, mid + 1, e, reversePairs);
    merge(arr, s, mid, e, reversePairs);
}

ll reversePairs(vector<int>& arr) {
    ll reversePairs = 0;
    mergeSort(arr, 0, arr.size() - 1, reversePairs);

    return reversePairs;
}