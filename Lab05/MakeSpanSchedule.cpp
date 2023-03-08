// Dao Trong Hoan
// 20204974
// Make Span Schedule

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
int n, m;
int duration[N];
int F[N];
int d[N];
typedef pair<int, int> ii;
vector<int> myvt[N];
vector<int> L;

void input()
{
    // fstream fsi("input.txt", ios::in);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> duration[i];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        myvt[u].push_back(v);
        d[v]++;
    }
}
void Topo()
{
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        L.push_back(v);
        for (int x : myvt[v])
        {
            d[x]--;
            if (!d[x])
                Q.push(x);
        }
    }
}
void solve()
{
    int ans = 0;
    memset(F, 0, sizeof(F));
    for (int u : L)
    {
        ans = max(ans, F[u] + duration[u]);
        for (int j : myvt[u])
        {
            F[j] = max(F[j], F[u] + duration[u]);
        }
    }
    cout << ans;
}
int main()
{
    input();
    Topo();
    solve();
    return 1;
}