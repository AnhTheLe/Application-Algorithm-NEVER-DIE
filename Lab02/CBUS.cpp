// Dao Trong Hoan
// 20204974
// CBUS
#include <bits/stdc++.h>
using namespace std;
#define N 50

int n, maxLoad;
int dist[N][N];
int cMin;
int load;
int f, f_best;
int x[N], x_best[N];
int appear[N];
void input()
{
    cin >> n >> maxLoad;
    cMin = 1e9;
    for (int i = 0; i <= 2 * n; i++)
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> dist[i][j];
            if (i != j)
                cMin = min(dist[i][j], cMin);
        }
}

int check(int v)
{
    if (appear[v] == 1)
        return 0;
    if (v > n)
    {
        if (!appear[v - n])
            return 0;
    }
    else
    {
        if (load + 1 > maxLoad)
            return 0;
    }
    return 1;
}

void solution()
{
    if (f + dist[x[n * 2]][0] < f_best)
    {
        f_best = f + dist[x[n * 2]][0];
        for (int i = 1; i <= 2 * n; i++)
        {
            x_best[i] = x[i];
        }
    }
}
void Try(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            x[k] = v;
            f += dist[x[k - 1]][x[k]];
            if (v <= n)
                load += 1;
            else
                load -= 1;
            appear[v] = 1;
            if (k == 2 * n)
                solution();
            else
            {
                if ((f + (2 * n - k + 1) * cMin) < f_best)
                    Try(k + 1);
            }
            if (v <= n)
                load -= 1;
            else
                load += 1;
            appear[v] = 0;
            f -= dist[x[k - 1]][x[k]];
        }
    }
}
int main()
{
    input();
    load = 0;
    f = 0;
    f_best = 1e9;
    for (int i = 1; i <= 2 * n; i++)
        appear[i] = 0;
    x[0] = 0;
    Try(1);
    cout << f_best;

    return 0;
}
