/** TESTING INPUT **
11 11
1 2
1 3
2 3
4 6
4 9
9 6
9 7
6 7
5 11
5 8
8 11
***** OUTPUT *****
1 - 0
2 - 0
3 - 0
4 - 1
5 - 2
6 - 1
7 - 1
8 - 2
9 - 1
10 - 3
11 - 2
******************/
#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<int> iComponent(1001, -1);

void Find_Component(int cur_comp, int u /* current node */)
{
    if (iComponent[u] != -1)
        return;

    iComponent[u] = cur_comp;

    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        Find_Component(cur_comp, v);
    }
}
int main(){
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

    // find component
    int num_comp = 0;
    for (int u = 1; u <= n; ++u)
    {
        if (iComponent[u] == -1)
        {
            Find_Component(num_comp, u);
            num_comp++;
        }
    }

    for(int i = 1; i <= n; i++){
        cout << i << " - " << iComponent[i] << endl;
    }
}