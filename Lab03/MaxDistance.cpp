// Dao Trong Hoan
// 20204974
// Max Distance Sub-sequence

#include <bits/stdc++.h>
using namespace std;
#define N 100006
long arr[N];
int t, n, c, m;

bool check(int distance)
{
    int count = 1;
    int i = 1;
    int last = 2;
    while (i < n)
    {
        while (last <= n && arr[last] - arr[i] < distance)
            ++last;
        if (last <= n)
            count++;
        if (count >= c)
            return true;
        i = last;
        last++; // Last lớn hơn i 1 đơn vị
    }
    return false;
}

int MaxDistance()
{
    int l = 0;
    int r = arr[n] - arr[1];
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + n);
        cout << MaxDistance() << endl;
    }
}
