// Dao Trong Hoan
// 20204974
// Connected Components of undirected graphs

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int n, m;
vector<int> myvt[N];
int visited[N];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        myvt[x].push_back(y);
        myvt[y].push_back(x);
        visited[i] = 0;
    }
}
void dfs(int u)
{
    visited[u] = 1;
    for (int v : myvt[u])
        if (visited[v] == 0)
            dfs(v);
}
int main()
{
    input();
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    cout << count;
    return 0;
}