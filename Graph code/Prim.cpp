/***** TESTING INPUT *****
7 11
1 4 5
4 6 6
4 5 15
2 3 8
3 5 5
5 7 9
6 7 11
4 2 9
2 5 7
1 2 7
6 5 8
***** OUTPUT *****
1 4 5
3 5 5
4 6 6
2 5 7
1 2 7
5 7 9
*****************/
#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u;      // vertex 1
    int v;      // vertex 2
    int weight; // weight

    edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};
// O(|V|^2) implementation
vector<edge> Prim(int n, vector<vector<edge>> Adj)
{
    vector<bool> bIn_T(n + 1, false); // Tap_Dinh_MST
    vector<edge> res;                 // Tap_Canh_MST
    vector<int> iBest_W(n + 1, 1e9), iBest_A(n + 1, -1);
    iBest_W[1] = 0;
    while (res.size() < n - 1)
    {
        int u = -1, v = -1, w = 1e9;
        for (int x = 1; x <= n; ++x)
            if (bIn_T[x] == false && iBest_W[x] < w)
            {
                u = iBest_A[x], v = x, w = iBest_W[x];
            }
        if (v == -1)
            return res; // Do_Thi_Khong_Lien_Thong
        bIn_T[v] = true;
        for (edge e : Adj[v])
            if (iBest_W[e.v] > e.weight)
            {
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;
            }
        if (v != 1)
            res.push_back({u, v, w});
    }
    return res;
}
// O((|V| + |E|)log|V|) implementation
vector<edge> mst(int n, vector<vector<edge>> Adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    vector<edge> res; // Tap_Canh_MST
    vector<int> iBest_W(n + 1, 1e9), iBest_A(n + 1, -1);
    iBest_W[1] = 0;
    PQ.push({iBest_W[1], 1});
    while (res.size() < n - 1)
    {
        while (!PQ.empty() &&
               PQ.top().first != iBest_W[PQ.top().second])
            PQ.pop();
        if (PQ.empty())
            return res; // G_Khong_Lien_Thong
        int w = PQ.top().first, v = PQ.top().second, u = iBest_A[v];
        for (edge e : Adj[v])
            if (iBest_W[e.v] > e.weight)
            {
                iBest_W[e.v] = e.weight;
                iBest_A[e.v] = e.u;
                PQ.push({iBest_W[e.v], e.v});
            }
        if (v != 1)
            res.push_back({u, v, w});
    }
    return res;
}

int main()
{
    // input
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2 [] weight
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
    }
    // preprocess : Adj = vector<vector<edge>> which represents edge from vertex v
    vector<vector<edge>> Adj(n + 1);
    for (edge e : edges)
    {
        Adj[e.u].push_back({e.u, e.v, e.weight});
        Adj[e.v].push_back({e.v, e.u, e.weight});
    }

    // prim
    cout << endl;
    for (edge e : mst(n, Adj))
    {
        cout << e.u << ' ' << e.v << ' ' << e.weight << endl;
    }
}
