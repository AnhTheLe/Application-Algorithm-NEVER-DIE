// Dao Trong Hoan
// 20204974
// Range Minimum Query
// O(n^2)

#include <bits/stdc++.h>
using namespace std;
vector<int> vt[1000000];

void preprocess(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        vt[i].push_back(i);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
            if (arr[vt[i].back()] < arr[j])
                vt[i].push_back(vt[i].back());
            else
                vt[i].push_back(j);
    }

}
int main()
{
    int a[100000], n, m, L, R, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    preprocess(a, n);

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L;
        cin >> R;
        sum = sum + a[vt[L].at(R - L)];
    }
    cout << sum;
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
int tree[100000];
int a[100000];
void makeNode(int L, int R, int index)
{
    int mid;
    if (L == R)
    {
        tree[index] = a[L];
        return;
    }
    mid = (L + R) / 2;
    makeNode(L, mid, 2 * index);
    makeNode(mid + 1, R, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}
int findMin(int u, int v, int L, int R, int index)
{
    int mid;
    if (u <= L && R <= v)
        return tree[index];
    mid = (L + R) / 2;
    if (v <= mid)
        return (findMin(u, v, L, mid, index * 2));
    if (u > mid)
        return (findMin(u, v, mid + 1, R, index * 2 + 1));
    return (min(findMin(u, v, L, mid, index * 2), findMin(u, v, mid + 1, R, index * 2 + 1)));
}
int main()
{
    int n, m, L, R, x, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    makeNode(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> L >> R;
        sum += findMin(L+1, R+1, 1, n, 1);
    }
    cout << sum;
    return 0;
}*/