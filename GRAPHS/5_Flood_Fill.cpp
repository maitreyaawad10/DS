#include <bits/stdc++.h>

using namespace std;

void dfs(int row, int col, int iniColor, int newColor, vector<vector<int>> &ans, vector<vector<int>> &image, int delRow[], int delCol[])
{
    ans[row][col] = newColor;
    int n = ans.size();
    int m = ans[0].size();

    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            image[newRow][newCol] == iniColor && ans[newRow][newCol] != newColor)
        {
            dfs(newRow, newCol, iniColor, newColor, ans, image, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int iniColor = image[sr][sc];
    int n = ans.size();
    int m = ans[0].size();
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    dfs(sr, sc, iniColor, color, ans, image, delRow, delCol);

    return ans;
}