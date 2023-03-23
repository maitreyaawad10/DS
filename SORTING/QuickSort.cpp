#include <bits/stdc++.h> 

using namespace std;

int partition(vector<int> &arr, int s, int e){
    int pivot = arr[s];
    int pivotIndex = -1;

    int i = s, j = e;

    while(i < j){
        while(arr[i] <= pivot && i < e)
            i++;
        
        while(arr[j] > pivot && j > s)
            j--;

        if(i < j)
            swap(arr[i], arr[j]);
    }

    pivotIndex = j;
    swap(arr[s], arr[pivotIndex]);

    return pivotIndex;
}

void solve(vector<int> &arr, int s, int e){
    // BASE CASE
    if(s >= e)
        return;

    // PARTITION INDEX
    int partitionIndex = partition(arr, s, e);

    // SORTING THE LEFT PARTITION
    solve(arr, s, partitionIndex - 1);

    // SORTING THE RIGHT PARTITION
    solve(arr, partitionIndex + 1, e);
}

vector<int> quickSort(vector<int> arr)
{
    int n = arr.size();
    solve(arr, 0, n - 1);
    
    return arr;
}