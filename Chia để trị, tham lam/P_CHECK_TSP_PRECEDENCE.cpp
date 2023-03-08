#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
int x[MAXN], d[MAXN][MAXN];
vector<int> adj[MAXN];
int in_degree[MAXN], dist[MAXN];
bool visited[MAXN];

bool topological_sort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            visited[i] = true;
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        x[++cnt] = u;
        for (int v : adj[u]) {
            if (!visited[v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    return cnt == n;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    cin >> m;
    memset(in_degree, 0, sizeof(in_degree));
    for (int k = 1; k <= m; k++) {
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        in_degree[j]++;
    }
    if (!topological_sort()) {
        cout << "-1\n";
        return 0;
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[x[1]] = 0;
    for (int i = 1; i < n; i++) {
        int u = x[i];
        for (int v : adj[u]) {
            dist[v] = min(dist[v], dist[u] + d[u][v]);
        }
    }
    int ans = dist[x[n]];
    cout << ans << "\n";
    return 0;
}
