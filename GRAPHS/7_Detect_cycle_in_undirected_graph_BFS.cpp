#include <bits/stdc++.h>

using namespace std;

bool bfs(int src, int vis[], vector<int> adj[])
{
    queue<pair<int, int>> q;

    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto value : adj[node])
        {
            if (!vis[value])
            {
                q.push({value, node});
                vis[value] = 1;
            }
            else if (vis[value] == 1 && parent != value)
            {
                return true;
            }
        }
    }

    return false;
}

// Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            if (bfs(i, vis, adj) == 1)
                return true;
        }
    }

    return false;
}