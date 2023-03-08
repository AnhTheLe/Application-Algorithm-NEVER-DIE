// Dao Trong Hoan
// 20204974
// GoldMining
#include <bits/stdc++.h>
using namespace std;
const int N = 1000001;
int arr[N];
int n, L1, L2, res;
int F[N];
deque<int> Q;
priority_queue<int> PQ;
typedef pair<int, int> ii;
void input()
{
    fstream fsi("test.txt", ios::in);
    cin >> n >> L1 >> L2;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        F[i] = arr[i];
    }
    Q.push_back(1);
}
// int Max(int i)
// {
//     int ans = 0;
//     for (int j = i - L2; j <= i - L1; j++)
//     {
//         int A;
//         if (j <= 0)
//             A = arr[i];
//         else
//             A = arr[i] + F[j];
//         ans = max(ans, A);
//     }
//     // cout<<ans<<endl;
//     return ans;
// }

void solve()
{

    for (int i = L1 + 1; i <= n; i++)
    {
        // Phương pháp tìm phần tử lớn nhất trong đoạn từ [i-L2, i-L1]
        while (!Q.empty() && F[Q.back()] <= F[i - L1])
            Q.pop_back();
        Q.push_back(i - L1);
        while (!Q.empty() && Q.front() <= i - L2)
            Q.pop_front();
        // Phần tử lớn nhất sẽ là phần tử đầu tiên
        F[i] = arr[i] + F[Q.front()];

    }
    int ans = F[1];
    for (int i = 2; i <= n; i++)
        ans = max(ans, F[i]);
    cout << ans;

 
}
void proc2()
{
    priority_queue<ii> hd;
    for (int i = 1; i <= n; i++)
    {
        if (i - L1 > 0)
            hd.push(ii(F[i - L1], i - L1)); // them f[i-l1] vao hang doi
        while (!hd.empty())
        { // xoa dan cac phan tu o vi tri dau hang doi
            if (hd.top().second < i - L2) // neu vi tri cua phan tu dau hang doi nho hon i-L2 
            // Có thể còn các phần tử chỉ số < i- L2 nhưng chúng nhỏ hơn top nên không cần xóa
                hd.pop();
            else
                break;
        }
        if (hd.empty())
            F[i] = arr[i];
        else
            F[i] = hd.top().first + arr[i]; // toi uu hoa cong thuc quy hoach dong
        res = max(F[i], res);
    }
    cout << res << "\n";
}
int main()
{
    input();
    for (int i = 1; i <= L1; i++)
    {
        PQ.push(F[i]);
    }
    // solve();
    proc2();
    return 0;
}