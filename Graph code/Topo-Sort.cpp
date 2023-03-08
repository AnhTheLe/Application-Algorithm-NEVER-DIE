/** TESTING INPUT ** CHANGE EDGE 7 10 to 10 7
7 9
1 2
1 3
2 3
3 4
2 4
6 4
4 5
5 7
6 7
***** OUTPUT *****
Topo Order : 1 2 3 6 4 5 7
*****************/
#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<int> iOrder;

void Topo_Sort(int u)
{
    if (bVisited[u])
        return;

    bVisited[u] = true;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        Topo_Sort(v);
    }
    iOrder.push_back(u);
}

int main()
{
    // input 
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; // number of vertexs and edges
    cin >> n >> m;
    // input edge: format - vertex 1 [] vertex 2
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(bVisited[i]) continue;
        Topo_Sort(i);
    }
    cout << "Topo Order : ";
    for(int i : iOrder){
        cout << i << ' ';
    }
}