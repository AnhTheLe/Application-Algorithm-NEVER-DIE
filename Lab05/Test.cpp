#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, t;
vector<int> adj[MAXN];
bool vis[MAXN];
int d[MAXN], low[MAXN];
bool ap[MAXN];

void dfs(int u, int p) {
    vis[u] = true;
    d[u] = low[u] = ++t;
    int cnt = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            low[u] = min(low[u], d[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= d[u] && p != -1) {
                ap[u] = true;
            }
            cnt++;
        }
    }
    if (p == -1 && cnt > 1) {
        ap[u] = true;
    }
}

void find_bridges_and_articulations() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_bridges_and_articulations();
    cout << "Articulation points:" << endl;
    for (int i = 1; i <= n; i++) {
        if (ap[i]) {
            cout << i << endl;
        }
    }
    cout << "Bridges:" << endl;
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (u < v && low[v] > d[u]) {
                cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}
