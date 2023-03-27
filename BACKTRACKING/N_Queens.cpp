#include <bits/stdc++.h> 

using namespace std;

// BRUTE FORCE APPROACH
bool isSafe(int row, int col, vector<string> &board, int n){
    int x = row;
    int y = col;

    while(y >= 0){
        if(board[x][y] == 'Q')
            return false;
        y--;
    }

    x = row;
    y = col;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 'Q')
            return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x < n && y >= 0){
        if(board[x][y] == 'Q')
            return false;
        x++;
        y--;
    }

    return true;
}

void findSolution(int n, vector<string> &board, vector<vector<string>> &ans, int col){
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; ++row){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            findSolution(n, board, ans, col + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for(int i = 0; i < n; ++i)
        board[i] = s;

    findSolution(n, board, ans, 0);

    return ans;
}

// OPTIMAL APPROACH
void findSolution(int n, vector<string> &board, vector<vector<string>> &ans, int col, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal){
    if(col == n){
        ans.push_back(board);
        return;
    }
    
    for(int row = 0; row < n; ++row){
        if((leftRow[row] == 0) && (lowerDiagonal[col + row] == 0) && (upperDiagonal[n - 1 + col - row] == 0)){
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;

            findSolution(n, board, ans, col + 1, leftRow, lowerDiagonal, upperDiagonal);
            
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');

    for(int i = 0; i < n; ++i)
        board[i] = s;
    
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);

    findSolution(n, board, ans, 0, leftRow, lowerDiagonal, upperDiagonal);

    return ans;
}