#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; // adjacency list
int disc[100005]; // discovery time of each node
int low[100005]; // lowest discovery time of a node reachable from current node
bool inStack[100005]; // whether a node is in the stack or not
stack<int> st; // stack to store nodes in order of their discovery times
int comp[100005]; // component array to store component number of each node
int num_components; // number of strongly connected components
int t; // current time

void tarjan(int u) {
    disc[u] = low[u] = ++t;
    st.push(u);
    inStack[u] = true;
    for(int v : adj[u]) {
        if(disc[v] == 0) { // v is not yet visited
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(inStack[v]) { // v is in the current SCC
            low[u] = min(low[u], disc[v]);
        }
    }
    if(disc[u] == low[u]) { // u is the root of its SCC
        while(true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            comp[v] = num_components;
            if(v == u) {
                break;
            }
        }
        num_components++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(inStack, false, sizeof(inStack));
    memset(comp, -1, sizeof(comp));
    num_components = 0;
    t = 0;
    for(int i=1; i<=n; i++) {
        if(disc[i] == 0) {
            tarjan(i);
        }
    }
    cout << num_components << endl;
    return 0;
}
