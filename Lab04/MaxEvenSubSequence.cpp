
// Dao Trong Hoan
// 20204974
// Max Even SubSequence

#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1000001;
long long arr[MAX];
long long n;
long long Sc[MAX], Sl[MAX];
long long ans = 0;
void input()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
}
int main()
{
    input();
    if (arr[1] % 2 == 0)
    {
        Sc[1] = arr[1];
        ans = max(ans, arr[1]);
        Sl[1] = 0;
    }
    else
    {
        Sl[1] = arr[1];
        Sc[1] = 0;
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            if (Sc[i - 1] > 0)
            {
                Sc[i] = Sc[i - 1] + arr[i];
            }
            else
            {
                Sc[i] = arr[i];
            }
            Sl[i] = Sl[i - 1] + arr[i];
            ans = max(ans, Sc[i]);
        }
        else
        {
            if (Sl[i - 1] > 0)
            {
                Sc[i] = Sl[i - 1] + arr[i];
            }
            else
            {
                Sc[i] = 0;
            }
            Sl[i] = Sc[i - 1] + arr[i];
            ans = max(ans, Sc[i]);
        }
    }
    cout << ans;
    return 0;
}
