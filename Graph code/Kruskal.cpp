/** TESTING INPUT **
11
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

struct edge{
    int u; // vertex 1
    int v; // vertex 2
    int weight; // weight

    edge(int _u, int _v, int _weight):
        u(_u), v(_v), weight(_weight){}
};
struct Union_Find
{
    vector<int> iParent;
    Union_Find(int n)
    {
        iParent = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            iParent[i] = i;
        }
    }
    // toan tu Find va Union
    int find(int x)
    {
        if (iParent[x] == x)
        {
            return x;
        }
        else
        {
            iParent[x] = find(iParent[x]); // Nen parent
            return iParent[x];
        }
    }

    void unite(int x, int y)
    {
        iParent[find(x)] = find(y);
    }
};

bool edge_cmp(const edge &a, const edge &b)
{
    return a.weight < b.weight;
}

vector<edge> Kruskal(int n, vector<edge> edges)
{
    Union_Find uf(n);
    sort(edges.begin(), edges.end(), edge_cmp);
    vector<edge> res;
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].u,
            v = edges[i].v;
        if (uf.find(u) != uf.find(v))
        {
           uf.unite(u, v);
            res.push_back(edges[i]);
        }
    }
    return res;
}

int main(){
    // input
    int n; // number of edges
    cin >> n;
    // input edge: format - vertex 1 [] vertex 2 [] weight
    vector<edge> edges;
    for(int i = 0; i < n; i++){
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(edge(u, v, weight));
    }
    // kruskal
    cout << endl;
    for(edge e : Kruskal(n, edges)){
        cout << e.u << ' ' << e.v << ' ' << e.weight << endl;
    }
}
