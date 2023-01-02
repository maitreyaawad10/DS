#include <bits/stdc++.h>

using namespace std;

int sumVec(vector<int> arr){
    int sum = 0;

    for(auto value : arr)
        sum += value;
    
    return sum;
}

bool isPossible(vector<int> arr, int n, int m, int mid){
    int pageSum = 0, studentCount = 1;

    for(int i = 0; i < n; ++i){
        if(pageSum + arr[i] <= mid)
            pageSum += arr[i];
        
        else{
            studentCount++;
            
            if(studentCount > m || arr[i] > mid)
                return false;
            
            pageSum = arr[i];
        }
    }

    return true;
}

// 10 20 30 40 , n = 4, m = 2
int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0, e = sumVec(arr), ans = -1;
    
    while(s <= e){
        int mid = s + ((e - s) / 2);

        if(isPossible(arr, n, m, mid)){
            ans = mid;
            e = mid - 1;
        }   
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int main(){
    
    return 0;
}