
// Dao Trong Hoan
// 20204974
// Nurse

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int N, K1, K2;
int arr[MAX];
int S0[MAX], S1[MAX];

void input()
{
    cin >> N >> K1 >> K2;
    for (int i = 1; i <= N; i++)
    {

        S0[i] = 0;
        S1[i] = 0;
    }
    S0[1] = 1;
    S1[K1] = 0;
    S0[0] = 1;
}
void solve()
{
    for (int i = 2; i <= N; i++)
    {
        for (int j = K1; j <= K2; j++)
        {
            if (i - j >= 0)
            {
                S1[i] += S0[i - j];
            }
        }
        S0[i] = S1[i - 1];
    }
}
int main()
{
    input();
    solve();
    cout << S1[N] + S0[N];
    return 0;
}
