// Dao Trong Hoan
// 20204974
// Disjoint Segment

#include <bits/stdc++.h>
using namespace std;

#define N 100000
pair<int, int> arr[N];
int last, c = 0;
int n;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
void solve()
{
    int ans = 0;
    last = -1;
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first > last)
        {
            ans++;
            last = arr[i].second;
        }
    }
    cout << ans;
}
int main()
{
    input();
    solve();
    return 0;
}