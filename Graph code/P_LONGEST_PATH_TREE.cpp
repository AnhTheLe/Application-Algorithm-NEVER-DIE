#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<pair<int,int>> adj[N];
int max_dist[N], farthest_node;

void dfs(int u, int p, int dist) {
    max_dist[u] = dist;
    for(auto e : adj[u]) {
        int v = e.first, w = e.second;
        if(v == p) continue;
        dfs(v, u, dist + w);
    }
    if(max_dist[u] > max_dist[farthest_node]) {
        farthest_node = u;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    farthest_node = 1;
    dfs(1, 0, 0);
    memset(max_dist, 0, sizeof(max_dist));
    dfs(farthest_node, 0, 0);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans = max(ans, max_dist[i]);
    }
    cout << ans << endl;
    return 0;
}
