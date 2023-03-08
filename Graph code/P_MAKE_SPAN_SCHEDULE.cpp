#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 2e5 + 5;

int n, m, d[MAXN], in_degree[MAXN];
vector<int> adj[MAXN];

int topo_sort() {
    queue<int> q;
    vector<int> earliest(n + 1);
    memset(earliest.data(), 0, (n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            earliest[i] = d[i];
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            in_degree[v]--;
            earliest[v] = max(earliest[v], earliest[u] + d[v]);
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, earliest[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    cout << topo_sort() << endl;
    return 0;
}
