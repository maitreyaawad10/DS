#include <bits/stdc++.h> 

using namespace std;

bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited, int x, int y, int n){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && (m[x][y] == 1) && (visited[x][y] == 0))
        return true;
        
    return false;
}

void solve(vector<vector<int>> &m, vector<string> &ans, vector<vector<int>> visited, string path, int x, int y, int n, int dirx[], int diry[]){
    // BASE CASE
    if(x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }


    string dir = "DLRU";
    
    for(int i = 0; i < 4; ++i){
        int newx = x + dirx[i];
        int newy = y + diry[i];
        
        if(isSafe(m, visited, newx, newy, n)){
            visited[x][y] = 1;
            solve(m, ans, visited, path + dir[i], newx, newy, n, dirx, diry);
            visited[x][y] = 0;  // BACKTRACKING
        }
    }
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<vector<int>> visited = m;
    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            visited[i][j] = 0;
    }
    
    int dirx[4] = {1, 0, 0, -1};
    int diry[4] = {0, -1, 1, 0};
    
    string path = "";
    int srcx = 0, srcy = 0;
    
    vector<string> ans;
    
    if(m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return ans;
    
    solve(m, ans, visited, path, srcx, srcy, n, dirx, diry);
    
    return ans;
}