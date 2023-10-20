#include <bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, -1, 0, +1};

    int minTime = 0;
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int tm = q.front().second;
        q.pop();

        minTime = max(minTime, tm);
        for (int i = 0; i < 4; ++i)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if ((newRow >= 0 && newRow < n) && (newCol >= 0 && newCol < m) &&
                (grid[newRow][newCol] == 1) && (!vis[newRow][newCol]))
            {
                q.push({{newRow, newCol}, tm + 1});
                vis[newRow][newCol] = 2;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
                return -1;
        }
    }

    return minTime;
}