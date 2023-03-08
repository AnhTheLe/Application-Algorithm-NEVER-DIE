#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int n, m;
int x[MAXN], d[MAXN][MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

bool dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (!dfs(v))
                return false;
        } else if (x[v] == -1) {
            return false;
        } else if (x[u] == -1 || x[u] > x[v]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> d[i][j];

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // check feasibility
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && !dfs(i)) {
            cout << "-1\n";
            return 0;
        }
    }

    // compute distance
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (d[x[i]][x[i + 1]] == 0) {
            cout << "-1\n";
            return 0;
        }
        ans += d[x[i]][x[i + 1]];
    }

    if (d[x[n]][x[1]] == 0) {
        cout << "-1\n";
        return 0;
    }
    ans += d[x[n]][x[1]];

    cout << ans << '\n';

    return 0;
}
