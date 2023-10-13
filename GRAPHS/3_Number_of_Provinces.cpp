#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adjLs[], int *visited)
{
    visited[node] = 1;

    for (auto value : adjLs[node])
    {
        if (!visited[value])
            dfs(value, adjLs, visited);
    }
}

int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjLs[V + 1];
    // since given adj matrix follows '0' based indexing hence this loop runs from 0 to V - 1
    // but in order to maintain the 1 based indexing in further code, we mark i + 1 and j + 1 in new adj list
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (adj[i][j] == 1 && i != j)
                adjLs[i + 1].push_back(j + 1);
        }
    }

    int visited[V + 1] = {0};
    int ans = 0;
    for (int i = 1; i <= V; ++i)
    {
        if (!visited[i])
        {
            ans++;
            dfs(i, adjLs, visited);
        }
    }

    return ans;
}