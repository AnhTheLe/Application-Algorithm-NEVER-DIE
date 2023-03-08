/** TESTING INPUT **
11 14
1 2
1 3
2 3
3 4
4 6
4 9
9 6
9 7
6 7
7 10
6 5
5 11
5 8
8 11
1 9
***** OUTPUT *****
3
******************/
#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];
void shortest_path(int u, int v){
    vector<int> iDist(1001, -1);
    queue<int> Q;
    Q.push(u);
    iDist[u] = 0;
    
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < Adj[u].size(); ++i)
        {
            int v = Adj[u][i];
            if (iDist[v] == -1)
            {
                Q.push(v);
                iDist[v] = 1 + iDist[u];
            }
        }
    }
    cout << iDist[v] << endl;
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
    // sort for increase order of vertex num
    for(int i = 1; i <= n; i++){
        sort(Adj[i].begin(), Adj[i].end());
    }
    
    int start, end;
    cin >> start >> end;
    shortest_path(start, end);
}
