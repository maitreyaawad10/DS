#include <bits/stdc++.h>

using namespace std;

void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty())
    {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();

        // delRow = deltaRow, delCol = deltaCol
        for (int delRow = -1; delRow <= 1; ++delRow)
        {
            for (int delCol = -1; delCol <= 1; ++delCol)
            {
                int newRow = currRow + delRow;
                int newCol = currCol + delCol;

                if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) && (grid[newRow][newCol] == '1') && (!visited[newRow][newCol]))
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
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
                bfs(row, col, visited, grid);
            }
        }
    }

    return ans;
}