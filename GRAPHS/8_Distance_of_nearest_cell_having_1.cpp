#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                ans[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    int delRow[4] = {-1, 0, +1, 0};
    int delCol[4] = {0, -1, 0, +1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int tm = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 0 && !vis[nRow][nCol])
            {
                ans[nRow][nCol] = 1 + tm;
                vis[nRow][nCol] = 1;
                q.push({{nRow, nCol}, tm + 1});
            }
        }
    }

    return ans;
}