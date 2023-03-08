#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; // adjacency list
vector<int> adjT[100005]; // transpose of adjacency list
bool vis[100005]; // visited array for first DFS
int comp[100005]; // component array to store component number of each node
stack<int> st; // stack to store nodes in order of their finishing times

void dfs1(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs1(v);
        }
    }
    st.push(u); // push node to stack after all its descendants are processed
}

void dfs2(int u, int c) {
    comp[u] = c;
    for(int v : adjT[u]) {
        if(comp[v] == -1) { // component not assigned yet
            dfs2(v, c);
        }
    }
}

int kosaraju(int n) {
    memset(vis, false, sizeof(vis));
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs1(i);
        }
    }
    
    memset(comp, -1, sizeof(comp));
    int c = 0; // component number
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        if(comp[u] == -1) { // component not assigned yet
            dfs2(u, c);
            c++;
        }
    }
    return c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjT[v].push_back(u); // transpose of adjacency list
    }
    int num_components = kosaraju(n);
    cout << num_components << endl;
    return 0;
}
