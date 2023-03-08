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
1 - 1 1
2 - 2 1
3 - 3 1
4 - 4 4
5 - 9 9
6 - 5 4
7 - 7 5
8 - 11 9
9 - 6 4
10 - 8 8
11 - 10 9
******************/
#include <bits/stdc++.h>
using namespace std;

const int n = 1001;
vector<int> Adj[n];
vector<int> Low(n), Num(n, -1);
int curnum = 0;
void AnalyzeDFS(int u /* current node */, int p /* parent */)
{
    Low[u] = Num[u] = ++curnum;
    for (int i = 0; i < Adj[u].size(); ++i)
    {
        int v = Adj[u][i];
        if (v == p)
            continue; // Khong_Xet_Dinh_Ngay_Truoc
        if (Num[v] == -1)
        {
            AnalyzeDFS(v, u);
            Low[u] = min(Low[u], Low[v]);
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
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

    AnalyzeDFS(1, 1);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " - " << Num[i] << ' ' << Low[i] << endl;
    }
    
}