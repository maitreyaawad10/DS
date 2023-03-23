#include <bits/stdc++.h>

using namespace std;

// USING INDICES INSTEAD OF SPLITTING THE ARRAY IN MERGE FUNCTION
void merge(vector < int > & arr, int s, int mid, int e){
    int leftArrayIndex = s, rightArrayIndex = mid + 1;

    vector<int> temp;

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

void solve(vector < int > & arr, int s, int e){
    if(s >= e)
        return;
  
    int mid = s + (e - s) / 2;

    solve(arr, s, mid);
    solve(arr, mid + 1, e);
    merge(arr, s, mid, e);
}

void mergeSort(vector < int > & arr, int n) {
    solve(arr, 0, n - 1);
}

// USING TWO DIFFERENT ARRAYS IN MERGE FUNCTION
void merge(vector < int > & arr, int s, int e){
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *leftArray = new int[len1];
    int *rightArray = new int[len2];

    int mainArrayIndex = s;
    for(int x = 0; x < len1; ++x)
        leftArray[x] = arr[mainArrayIndex++];

    // mainArrayIndex = mid + 1;
    for(int x = 0; x < len2; ++x)
        rightArray[x] = arr[mainArrayIndex++];

    int leftArrayIndex = 0, rightArrayIndex = 0;
    mainArrayIndex = s;

    while(leftArrayIndex < len1 && rightArrayIndex < len2){
        if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex])
            arr[mainArrayIndex++] = leftArray[leftArrayIndex++];
        
        else
            arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
    }

    while(leftArrayIndex < len1)
        arr[mainArrayIndex++] = leftArray[leftArrayIndex++];

    while(rightArrayIndex < len2)
        arr[mainArrayIndex++] = rightArray[rightArrayIndex++];

    delete []leftArray;
    delete []rightArray;
}

void mergeSort(int *arr, int s, int e){
    // Base Case
    if(s >= e)
        return;

    int mid = s + (e - s) / 2;

    // leftArray half
    mergeSort(arr, s, mid);

    // rightArray half
    mergeSort(arr, mid + 1, e);

    // merge two halves
    merge(arr, s, e);
}

int main(){
    int n = 8;

    int arr[n] = {8, 3, 4, 6, 9, 5, 7, 2};

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";  
    cout << endl;
    
    return 0;
}