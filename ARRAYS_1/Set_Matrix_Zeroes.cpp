#include <bits/stdc++.h>

using namespace std;

// OPTIMIZED APPROACH
void setZeroes(vector<vector<int>>& matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for(int i = 0; i < rows; ++i){
        if(matrix[i][0] == 0)   col0 = 0;
        for(int j = 1; j < cols; ++j){
            if(matrix[i][j] == 0)
                matrix[0][j] = matrix[i][0] = 0;
        }
    }

    for(int i = rows - 1; i >= 0; --i){
        for(int j = cols - 1; j >= 1; --j){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }

        if(col0 == 0)   
            matrix[i][0] = 0;
    }
}

int main(){

    vector<vector<int> > matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    setZeroes(matrix);

    return 0;
}


// UNOPTIMIZED APPROACH
// void setZeroes(vector<vector<int>>& matrix) {
//     set<int> row, col;
//     int m = matrix.size(), n = matrix[0].size();
    
//     for(int i = 0; i < m; ++i){
//         for(int j = 0; j < n; ++j){
//             if(matrix[i][j] == 0){
//                 row.insert(i);
//                 col.insert(j);
//             }
//         }
//     }   

//     for(auto it = row.begin(); it != row.end(); ++it){
//         int i = (*it);

//         for(int j = 0; j < n; ++j){
//             matrix[i][j] = 0;
//         } 
//     }

//     for(auto it = col.begin(); it != col.end(); ++it){
//         int j = (*it);

//         for(int i = 0; i < m; ++i){
//             matrix[i][j] = 0;
//         } 
//     }
// }