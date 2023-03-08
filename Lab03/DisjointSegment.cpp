// Dao Trong Hoan
// 20204974
// Disjoint Segment

#include <bits/stdc++.h>
using namespace std;

#define N 100000
int a[N], b[N];
int last, c = 0;
int n;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
}
void process()
{
    last = b[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > last)
        {
            c++;
            last = b[i];
        }
    }
}
void Merge(int a[], int b[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int arr1[N];
    int arr2[N];
    for (int k = l; k <= r; k++)
    {
        if (i > m)
        {
            arr1[k] = a[j];
            arr2[k] = b[j];
            j++;
        }
        else
        {
            if (j > r)
            {
                arr1[k] = a[i];
                arr2[k] = b[i];
                i++;
            }
            else
            {
                if (b[i] < b[j])
                {
                    arr1[k] = a[i];
                    arr2[k] = b[i];
                    i++;
                }
                else
                {
                    arr1[k] = a[j];
                    arr2[k] = b[j];
                    j++;
                }
            }
        }
    }

    for (int k = l; k <= r; k++)
    {
        a[k] = arr1[k];
        b[k] = arr2[k];
    }
}
void MergeSort(int a[], int b[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(a, b, l, m);
        MergeSort(a, b, m + 1, r);
        Merge(a, b, l, m, r);
    }
}
int main()
{
    input();
    MergeSort(a, b, 0, n - 1);
    process();
    cout << c + 1;
    return 0;
}
