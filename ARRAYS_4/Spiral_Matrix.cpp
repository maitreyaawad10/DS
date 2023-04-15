#include <bits/stdc++.h>

using namespace std;

// OPTIMAL APPROACH, TC : O(rows * cols), SC : O(rows * cols)
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int top = 0, left = 0, bottom = rows - 1, right = cols - 1;

    vector<int> ans;

    while(top <= bottom && left <= right){
        for(int i = left; i <= right; ++i){
            ans.push_back(matrix[top][i]);
        }    
        top++;

        for(int i = top; i <= bottom; ++i){
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
            for(int i = right; i >= left; --i){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right){
            for(int i = bottom; i >= top; --i){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}