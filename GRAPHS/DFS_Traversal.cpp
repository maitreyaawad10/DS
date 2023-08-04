#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> &visited, vector<int> adj[], vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    for (auto value : adj[node])
    {
        if (!visited[value])
            dfs(value, visited, adj, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> ans;
    int start = 0;

    dfs(start, visited, adj, ans);

    return ans;
}