#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 10000;
const int MAXM = 10000;

vector<int> T[MAXN+1];
int match[MAXM+1];
bool vis[MAXM+1];

bool dfs(int u) {
    for (int i = 0; i < T[u].size(); i++) {
        int v = T[u][i];
        if (!vis[v]) {
            vis[v] = true;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int max_matching(int n, int m) {
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int u = 1; u <= n; u++) {
        memset(vis, false, sizeof(vis));
        if (dfs(u)) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int t;
            cin >> t;
            T[i].push_back(t);
        }
    }
    int ans = max_matching(n, m);
    cout << ans << endl;
    return 0;
}
