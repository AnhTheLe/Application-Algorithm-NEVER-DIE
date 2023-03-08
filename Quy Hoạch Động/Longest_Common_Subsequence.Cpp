#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

int n, m;
int X[N], Y[N];
int arr[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int i = 1; i <= m; i++) cin >> Y[i];

    for (int i = 1; i <= n; i++)
    {
        int j = lower_bound(Y + 1, Y + m + 1, X[i]) - Y;
        if (j <= m) arr[i] = max(arr[i], arr[i - 1] + 1);
    }

    cout << *max_element(arr, arr + n + 1) << endl;

    return 0;
}
