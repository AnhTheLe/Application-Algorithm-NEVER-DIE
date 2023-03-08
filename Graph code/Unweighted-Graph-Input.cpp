#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];

// The input should be :
// Line 1 : n - number of vertexs; m - number of edges
// Line 2 -> m + 1 - start [] end (edge) 

void unweighted_bidirectional_graph(){
    // input 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    // sort for increase order of vertex num
    for(int i = 1; i <= n; i++){
        sort(Adj[i].begin(), Adj[i].end());
    }
}

void unweighted_directional_graph(){
    // input 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
    }
    // sort for increase order of vertex num
    for(int i = 1; i <= n; i++){
        sort(Adj[i].begin(), Adj[i].end());
    }
}