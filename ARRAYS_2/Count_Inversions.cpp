#include <bits/stdc++.h> 

using namespace std;
#define ll long long

// BRUTE FORCE, TC : O(N^2), SC : O(1)


// OPTIMAL APPROACH, TC : O(N*LOG(N)), SC : O(N)
// CODE : BY USING INDICES IN MERGE FUNCTION
void merge(ll *arr, ll s, ll mid, ll e, ll &inversionsCount){
    ll leftArrayIndex = s, rightArrayIndex = mid + 1;

    vector<ll> temp;

    while(leftArrayIndex <= mid && rightArrayIndex <= e){
        if(arr[leftArrayIndex] > arr[rightArrayIndex]){
            temp.push_back(arr[rightArrayIndex++]);
            inversionsCount += (mid - leftArrayIndex) + 1;
        }
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

void mergeSort(ll *arr, ll s, ll e, ll &inversionsCount){
    if(s >= e)
        return;
  
    ll mid = s + (e - s) / 2;

    mergeSort(arr, s, mid, inversionsCount);
    mergeSort(arr, mid + 1, e, inversionsCount);
    merge(arr, s, mid, e, inversionsCount);
}

ll getInversions(ll *arr, ll n){
    ll inversionsCount = 0;

    mergeSort(arr, 0, n - 1, inversionsCount);

    return inversionsCount;
}

// OPTIMAL APPROACH, TC : O(N*LOG(N)), SC : O(N)
// CODE : BY BREAKING TWO ARRAYS IN MERGE FUNCTION
void merge(ll *arr, ll s, ll e, ll &inversionsCount){
    ll mid = s + (e - s) / 2;

    ll len1 = mid - s + 1;
    ll len2 = e - mid;

    ll *leftArray = new ll[len1];
    ll *rightArray = new ll[len2];

    ll mainArrayIndex = s;
    for(ll x = 0; x < len1; ++x)
        leftArray[x] = arr[mainArrayIndex++];

    for(ll x = 0; x < len2; ++x)
        rightArray[x] = arr[mainArrayIndex++];

    ll leftArrayIndex = 0, rightArrayIndex = 0;
    mainArrayIndex = s;

    while(leftArrayIndex < len1 && rightArrayIndex < len2){
        if(leftArray[leftArrayIndex] > rightArray[rightArrayIndex]){
            arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
            inversionsCount = inversionsCount + (len1 - leftArrayIndex);
        }
        
        else
            arr[mainArrayIndex++] = leftArray[leftArrayIndex++];
    }

    while(leftArrayIndex < len1)
        arr[mainArrayIndex++] = leftArray[leftArrayIndex++];

    while(rightArrayIndex < len2)
        arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
    
    delete []leftArray;
    delete []rightArray;
}

void mergeSort(ll *arr, ll s, ll e, ll &inversionsCount){
    if(s >= e)
        return;

    ll mid = s + (e - s) / 2;

    mergeSort(arr, s, mid, inversionsCount);
    mergeSort(arr, mid + 1, e, inversionsCount);
    merge(arr, s, e, inversionsCount);
}

ll getInversions(ll *arr, int n){
    ll inversionsCount = 0;
    
    mergeSort(arr, 0, n - 1, inversionsCount);

    return inversionsCount;
}