#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int count_components(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n+1, false);
    int count = 0;
    for (int u = 1; u <= n; u++) {
        if (!visited[u]) {
            dfs(u, adj, visited);
            count++;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1); // adjacency list to store graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // add undirected edge between u and v
        adj[v].push_back(u);
    }

    int components = count_components(n, adj);
    cout << components << endl;

    return 0;
}
