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
***** OUTPUT *****
Bridges : 
7 10
6 5
3 4
******************/
#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<int> Adj[N], Low(N), Num(N, -1);
int curnum = 0;
vector<pair<int, int>> iiBridges;

void Find_Bridges(int u, int p)
{
    Low[u] = Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (v == p)
            continue;
        if (Num[v] == -1)
        {
            Find_Bridges(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u])
            iiBridges.push_back(make_pair(u, v));
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

    Find_Bridges(1, 1);

    cout << "Bridges : " << endl;
    for(int i = 0; i < iiBridges.size(); i++){
        cout << iiBridges[i].first << ' ' << iiBridges[i].second << endl;
    }
}