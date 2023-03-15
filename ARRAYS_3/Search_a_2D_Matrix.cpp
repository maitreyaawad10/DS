#include <bits/stdc++.h> 

using namespace std;

/*
BRUTE FORCE APPROACH, TC : O(M * N)
APPLY LINEAR SEARCH AND SEARCH FOR ELEMENT
*/

// BETTER APPROACH, TC : O(M + N)
// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     int i = 0, j = cols - 1;

//     while(i < rows && j >= 0){
//         if(matrix[i][j] == target)
//             return true;

//         if(matrix[i][j] < target)
//             i++;
//         else if(matrix[i][j] > target)
//             j--;
//     }

//     return false;
// }

// OPTIMAL APPROACH, TC : O(log(M * N))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int s = 0, e = (rows * cols) - 1;

    while(s <= e){
        int mid = (s + (e - s) / 2);

        if(matrix[mid / cols][mid % cols] == target)
            return true;

        if(matrix[mid / cols][mid % cols] < target)
            s = mid + 1;

        else
            e = mid - 1;
    }

    return false;
}
