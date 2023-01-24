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

/*
int peakIndex(vector<int>& arr, int n) {
        int s = 0, e = n - 1, ans = -1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                ans = mid;
                return ans;
            }

            if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
                s = mid;
            
            else
                e = mid;
        }

        return -1;
    }
*/

int main(){



    return 0;
}