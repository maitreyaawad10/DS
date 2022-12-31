#include <bits/stdc++.h>

using namespace std;

int peakIndex(vector<int>& arr, int n) {
    int start = 0, end = n - 1;

    while(start < end){
        int mid = start + ((end - start) / 2);

        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return start;
}


int main(){



    return 0;
}