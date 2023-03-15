#include <bits/stdc++.h>

using namespace std;

// LEETCODE
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int n = matrix.size(), m = matrix[0].size();
    int s = 0, e = (n * m) - 1;

    while(s <= e){
        int mid = s + (e - s) / 2;

        if(matrix[mid / m][mid % m] == target)
            return true;

        if(matrix[mid / m][mid % m] < target)
            s = mid + 1;

        else
            e = mid - 1;
    }

    return false;
}

/*
GEEKS FOR GEEKS

    int i = 0, j = m - 1;
        
    while(i < n && j >= 0){
        if(target == matrix[i][j])
            return 1;
        
        if(target > matrix[i][j])
            i++;
            
        else
            j--;
    }
    
    return 0;
*/