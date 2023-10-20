#include <bits/stdc++.h>

using namespace std;

bool dfs(int src, int parent, int vis[], vector<int> adj[])
{
    vis[src] = 1;

    for (auto value : adj[src])
    {
        if (!vis[value])
        {
            if (dfs(value, src, vis, adj) == true)
                return true;
        }
        else if (vis[value] == 1 && value != parent)
        {
            return true;
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
            if (dfs(i, -1, vis, adj) == true)
                return true;
        }
    }

    return false;
}