#include <bits/stdc++.h>

using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int> visited(n, 0);
    vector<int> bfs;

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int qTop = q.front();
        q.pop();

        for (auto value : adj[qTop])
        {
            if (!visited[value])
            {
                visited[value] = 1;
                q.push(value);
            }
        }

        bfs.push_back(qTop);
    }

    return bfs;
}