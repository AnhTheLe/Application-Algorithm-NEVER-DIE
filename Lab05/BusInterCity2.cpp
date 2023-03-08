// Dao Trong Hoan
// 20204974
// Name: Bus inter-city
#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int n, m;
int C[N], D[N];
vector<int> myvt[N];
int dist[N][N];
int dist2[N];
int arr[N][N];
typedef pair<int, int> ii;
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
    myq.push(s);
    while (!myq.empty())
    {
        int u = myq.front();
        myq.pop();
        for (int v : myvt[u])
            if (dist[s][v] == 0)
            {
                dist[s][v] = dist[s][u] + 1;
                dist[v][s] = dist[s][v];
                myq.push(v);
            }
    }
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
        dist2[i] = 1e9;
    dist2[1] = 0;
    mypq.push(ii(0, 1));
    while (!mypq.empty())
    {
        int u = mypq.top().second;
        int du = mypq.top().first;
        mypq.pop();
        if (du != dist2[u])
            continue;

        for (int i = 1; i <= n; i++)
            if (dist[u][i] <= D[u] && dist2[i] > dist2[u] + C[u])
            {
                dist2[i] = dist2[u] + C[u];
                mypq.push(ii(dist2[i], i));
            }
    }

    printf("%d", dist2[n]);
}
int main()
{
    input();
    for (int i = 1; i <= n; i++)
        BFS(i);
    dijkstra();
    return 0;
}
