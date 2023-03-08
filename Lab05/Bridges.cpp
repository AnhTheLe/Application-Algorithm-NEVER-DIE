// Dao Trong Hoan
// 20204974
// Bridges

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> myvt[N], Low(N), Num(N);
int timer = 0;
typedef pair<int, int> ii;
int countBridges = 0;
int countPoints = 0;
int n, m;
bool check[N];
void input()
{
    fstream fsi("test.txt", ios::in);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        myvt[u].push_back(v);
        myvt[v].push_back(u);
    }
}
void findBridges(int u, int p)
{
    timer++;
    Low[u] = Num[u] = timer;
    int numChild = 0;

    for (int i = 0; i < myvt[u].size(); i++)
    {
        int v = myvt[u][i];
        if (v == p)
            continue;
        if (!Num[v]) // Nếu v chưa được thăm
        {
            findBridges(v, u); // Thăm v với gốc là u
            numChild++;
            Low[u] = min(Low[u], Low[v]);
            if (p == -1)
            {
                if (numChild > 1)
                    check[u] = true;
            }
            else
            {
                if (Low[v] >= Num[u])
                    check[u] = true;
            }
        }
        else
        {
            Low[u] = min(Low[u], Num[v]);
        }
        if (Low[v] > Num[u])
        {
            countBridges++;
        }
    }
}

int main()
{
    input();
    for (int i = 1; i <= n; i++)
        Num[i] = 0;
    for (int i = 1; i <= n; i++)
        if (!Num[i])
            findBridges(i, -1);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i == 1 && myvt[i].size() < 2)
    //         continue;
    //     for (int j = 0; j < myvt[i].size(); j++)
    //         if (Num[i] <= Low[myvt[i][j]])
    //             countPoints++;
    // }
    for (int i = 1; i <= n; i++)
        if (check[i])
            countPoints++;
    cout << countPoints << " " << countBridges;
    return 0;
}