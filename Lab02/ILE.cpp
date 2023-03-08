// Dao Trong Hoan
// 20204974
// Integer Linear Equation
const int N = 1000001;
int arr[N];
int t[N];
int n, m, x, dem = 0, f = 0;

#include <bits/stdc++.h>
using namespace std;

void Try(int x, int f)
{
    for (int j = 1; j <= (m - f - (t[n] - t[x])) / arr[x]; j++)
    {
        int s = f;
        s += j * arr[x];
        if (x < n)
            Try(x + 1, s);
        else if (s == m)
            dem++;
    }
}

int main()
{
    cin >> n >> m;
    int x = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        x += arr[i];
        t[i] = x;
    }
    Try(1, 0);
    cout << dem;
    return 0;
}