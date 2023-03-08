// Dao Trong Hoan
// 20204974
// Name: Bus inter-city
#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int n, m;
int C[N], D[N];
vector<int> myvt[N];
int dist[N];
int dist2[N];
int arr[N][N];
typedef pair<int, int> ii;
vector<ii> New[N];
vector<int> myvt2[N];
priority_queue<ii> mypq;

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &C[i], &D[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        myvt[u].push_back(v);
        myvt[v].push_back(u);
    }
}
void BFS(int s)
{
    queue<int> myq;
    int u, v;
    memset(dist, 0, sizeof(dist));
    myq.push(s);
    while (!myq.empty())
    {
        u = myq.front();
        myq.pop();
        if (dist[u] == D[s]) // Nếu u đã được duyệt trước đó và có độ dài đường đi từ s đến u bằng D[s] thì bỏ qua
            continue;        //
        for (int i = 0; i < int(myvt[u].size()); i++)
        {
            v = myvt[u][i];
            if (dist[v] == 0 && v != s)
            {
                dist[v] = dist[u] + 1;
                myq.push(v);
                New[s].push_back(ii(C[s], v)); // C[v] la chi phi di tu s den v
            }
        }
    }
}

void dijkstra()
{

    for (int i = 2; i <= n; i++)
        dist2[i] = 1e9;
    int u, v, du;
    dist2[1] = 0;
    mypq.push(ii(0, 1));
    while (!mypq.empty())
    {
        u = mypq.top().second;
        du = mypq.top().first;
        if (du != dist2[u])
            continue;
        mypq.pop();
        if (du != dist2[u])
            continue;
        for (int i = 0; i < int(New[u].size()); i++)
        {
            v = New[u][i].second;
            if (dist2[v] > dist2[u] + New[u][i].first)
            {
                dist2[v] = dist2[u] + New[u][i].first;
                mypq.push(ii(dist2[v], v));
            }
        }
    }
}
int main()
{
    input();
    for (int i = 1; i <= n; i++)
        BFS(i);
    dijkstra();
    printf("%d", dist2[n]);
    return 0;
}
