// Dao Trong Hoan
// 20204974
// Ware House

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int N, T, D;
int arr[MAX], t[MAX];
int f[MAX][101];

void input()
{
    cin >> N >> T >> D;
    arr[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }
}


// Bài toán con
// Gọi F[i][k] là mảng lưu trữ số lượng hàng hóa tối đa mà thời gian không lớn hơn k và kho i được chọn
// F[i][k] = 0 khi k < t[i]
// F[i][k] = max(F[j][k - t[i]] + arr[i]) với j: Xét các kho có khoảng cách hợp lệ, thời gian nhỏ hơn k - t[i]

void solve()
{
    for (int k = 1; k <= T; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (k < t[i])
            {
                f[i][k] = 0;
            }
            else
            {
                int ans = 0;
                for (int j = i - D; j <= i - 1; j++)
                {
                    if (j <= 0)
                    {
                        ans = max(ans, arr[i]);
                    }
                    else
                    {
                        ans = max(ans, arr[i] + f[j][k - t[i]]); // j: i - D -> i - 1 xét các khoảng cách hợp lệ k-t[i] khoảng thời gian hợp lệ
                    }
                }
                f[i][k] = ans;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= T; j++)
        {
            ans = max(ans, f[i][j]);
        }
    }

    // Ma trận f[i][j] là số lượng hàng hóa tối đa có thể đem về kho từ khoảng thời gian 1 -> j, với khoảng cách từ kho 1 -> i
    cout << ans;
}
int main()
{
    input();
    solve();
    return 0;
}