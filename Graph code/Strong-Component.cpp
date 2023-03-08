/** TESTING INPUT **
11 14
1 2
2 3
3 1
3 4
4 6
6 9
9 4
7 9
6 7
7 10
6 5
5 8
8 11
11 5
***** OUTPUT *****
//TPLT: 10 
///TPLT: 11 8 5
//TPLT: 7 9 6 4
//TPLT: 3 2 1
*****************/
#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[10001];
vector<int> Low(10001), Num(10001, -1);
vector<bool> bConnect(10001, false);
int curnum = 0;

stack<int> iComp;

void SCC(int u)
{
    iComp.push(u);
    bConnect[u] = true;
    Low[u] = Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (Num[v] == -1)
        {
            SCC(v);
            Low[u] = min(Low[u], Low[v]);
        }
        else if (bConnect[v])
        {
            Low[u] = min(Low[u], Num[v]);
            
        }
    }
    if (Num[u] == Low[u])
    {
        cout << "TPLT: ";
        while (true)
        {
            int cur = iComp.top();
            iComp.pop();
            bConnect[cur] = false;
            cout << cur << " ";
            if (cur == u) break;
            
        }
        cout << endl;
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
    }

    for (int i = 1; i <= n; ++i)
        if (Num[i] == -1)
            SCC(i);
    return 0;
}