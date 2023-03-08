// Dao Trong Hoan
// 20204974
// Range Minimum Query

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int oo = 1e9 + 7;
int n;
int arr[N];
int tree[4 * N];

void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = arr[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
}
int findMin(int node, int start, int end, int left, int right)
{
    if (left > end || right < start)
        return oo;
    if (left <= start && right >= end)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = findMin(2 * node, start, mid, left, right);
    int p2 = findMin(2 * node + 1, mid + 1, end, left, right);
    return min(p1, p2);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    build(1, 1, n);
    int v;
    cin >> v;
    int sum = 0;
    for (int i = 1; i <= v; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += findMin(1, 1, n, x + 1, y + 1);
    }
    cout << sum;
}
