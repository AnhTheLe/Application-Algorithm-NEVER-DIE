#include <bits/stdc++.h>
using namespace std;
#define INF 9999999
struct edge
{
    int u;      // vertex 1
    int v;      // vertex 2
    int weight; // weight

    edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};
vector<edge> Adj[100];
vector<int> iDist(100, INF);

// The input should be :
// Line 1 : n - number of vertexs; m - number of edges
// Line 2 -> m + 1 - start [] end [] weight
void weighted_bidirectional_graph(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // input
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2 [] weight
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
    }
    // preprocess : Adj = vector<edge>[] which represents edge from vertex v
    for(edge e : edges){
        Adj[e.u].push_back({e.u, e.v, e.weight});
        Adj[e.v].push_back({e.v, e.u, e.weight});
    }
}

void weighted_directional_graph(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // input
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2 [] weight
    vector<edge> edges;
    for(int i = 0; i < m; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
    }
    // preprocess : Adj = vector<edge>[] which represents edge from vertex v
    for(edge e : edges){
        Adj[e.u].push_back({e.u, e.v, e.weight});
    }
}
