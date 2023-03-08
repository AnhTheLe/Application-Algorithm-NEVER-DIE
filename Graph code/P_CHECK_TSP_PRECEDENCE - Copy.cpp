#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x[i]--; // convert 1-based to 0-based index
    }

    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    cin >> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // convert 1-based to 0-based index
        adj[u].push_back(v);
        indeg[v]++;
    }

    // check if the sequence x is a permutation of 0..n-1
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (x[i] < 0 || x[i] >= n || used[x[i]]) {
            cout << -1 << endl;
            return 0;
        }
        used[x[i]] = true;
    }

    // check if the sequence x satisfies the precedence constraints
    for (int i = 0; i < n; i++) {
        for (int j : adj[x[i]]) {
            if (find(x.begin(), x.begin() + i, j) == x.begin() + i) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // compute the total travel distance of the route
    int dist = 0;
    for (int i = 0; i < n; i++) {
        if (indeg[x[i]] == 0) {
            int j = i;
            while (j < n && indeg[x[j]] == 0) {
                j++;
            }
            if (j < n && indeg[x[j]] > 0) {
                cout << -1 << endl;
                return 0;
            }
            int prev = x[j-1];
            for (int k = j-2; k >= i; k--) {
                int cur = x[k];
                dist += d[cur][prev];
                prev = cur;
            }
            dist += d[x[i]][prev];
            i = j-1;
        }
    }

    cout << dist << endl;
    
    return 0;
}
