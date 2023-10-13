#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    // delRow = deltaRow, delCol = deltaCol
    for (int delRow = -1; delRow <= 1; ++delRow)
    {
        for (int delCol = -1; delCol <= 1; ++delCol)
        {
            int newRow = row + delRow;
            int newCol = col + delCol;

            if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && (grid[newRow][newCol] == '1') && (!visited[newRow][newCol]))
            {
                dfs(newRow, newCol, visited, grid);
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            if (!visited[row][col] && grid[row][col] == '1')
            {
                ans++;
                dfs(row, col, visited, grid);
            }
        }
    }

    return ans;
}