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
1
***** OUTPUT *****
1 -> 1 : 0
1 -> 2 : 7
1 -> 3 : 15
1 -> 4 : 5
1 -> 5 : 14
1 -> 6 : 11
1 -> 7 : 22
*****************/
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
int iDist[1001][1001];
int Weight[1001][1001];
void Floyd_Warshall(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            iDist[i][j] = (i == j) ? 0 : Weight[i][j];
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                iDist[i][j] =
                    min(iDist[i][j], iDist[i][k] + iDist[k][j]);
            }
        }
    }
}

int main(){
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
    // preprocess : Weight[u][v] = weight of edge u to v
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            Weight[i][j] = INF;
        }
    }
    for(edge e : edges){
        Weight[e.u][e.v] = Weight[e.v][e.u] = e.weight; 
    }
    int start;
    cin >> start;
    Floyd_Warshall(n);
    for(int i = 1; i <= n; i++){
        cout << start << " -> " << i << " : " << iDist[start][i] << endl;
    }
}
