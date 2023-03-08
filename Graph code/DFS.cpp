/** TESTING INPUT **
11 17
1 2
1 3
4 1
3 4
3 2
2 5
6 3
5 6
6 4
6 9
6 7
6 8
7 9
7 8
8 11
9 10
10 9
***** OUTPUT *****
1 2 5 6 3 4 7 8 11 9 10 
******************/

#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
vector<bool> bVisited(1001, false);
vector<bool> bMarked(1001, false);
vector<int>  dfsOrder(0);
void DFS(int u)
{
    if (bMarked[u])
        return;
    // Process //
    dfsOrder.push_back(u);
    /////////////
    bMarked[u] = true;
    bVisited[u] = true;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        bVisited[v] = true;
        DFS(v);
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
    }
    // sort for increase order of vertex num
    for(int i = 1; i <= n; i++){
        sort(Adj[i].begin(), Adj[i].end());
    }

    DFS(1);
    for(int i : dfsOrder){
        cout << i << ' ';
    }
}