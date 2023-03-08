#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // set infinity to max int value

int main() {
    int n, m, s, t;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1); // adjacency list to store graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // add directed edge from u to v with weight w
    }

    cin >> s >> t;

    vector<int> dist(n+1, INF); // initialize all distances to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue to store (distance, node) pairs
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // skip outdated distance updates

        for (auto neighbor : adj[u]) { // loop over neighbors of u
            int v = neighbor.first;
            int w = neighbor.second;
            if (dist[u] + w < dist[v]) { // update distance to v if shorter path found
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF) cout << "-1" << endl; // no path found from s to t
    else cout << dist[t] << endl; // output shortest distance from s to t

    return 0;
}
