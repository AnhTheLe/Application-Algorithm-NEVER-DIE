/** TESTING INPUT **
7 7
7 1
1 2
7 3
3 2
2 6
2 5
2 4
***** OUTPUT *****
1
*****************/
#include <bits/stdc++.h>
using namespace std;

vector<int> Adj[1000];
vector<int> iSide(1001, -1);
bool is_bipartite = true;
void Check_Bipartite(int u)
{
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (iSide[v] == -1)
        {
            iSide[v] = 1 - iSide[u];
            Check_Bipartite(v);
        }
        else if (iSide[u] == iSide[v])
        {
            is_bipartite = false;
        }
    }
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
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    // sort for increase order of vertex num
    for(int i = 1; i <= n; i++){
        sort(Adj[i].begin(), Adj[i].end());
    }

    for (int u = 0; u < n; u++)
        if (iSide[u] == -1)
        {
            iSide[u] = 0;
            Check_Bipartite(u);
        }
    cout << is_bipartite << endl;
    return 0;
}