#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int t,n,c;
int x[MAX];

void input() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
}

bool check(int distance) {
    int s1 = 1;
    int i = 1, j = 2;
    while (i < n) {
        while (j <= n && x[j] - x[i] < distance) 
            ++j;
        if (j <= n) 
            s1++; 
        if (s1 >= c)
            return true;
        i = j;
        j++;
    }
    return false;
}

void solve() {
    sort(x,x+n+1);
    int l = 0, r = x[n] - x[1];
    // int d = (x[n] - x[1] + 1)/2;
    // while (!check(d) && d > 1)
    //     d--;
    // cout << d << endl;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1; // Thử kết quả ở nửa phải với distance++
        else r = mid - 1;   // Thử kết quả ở nửa trái với distance--
    }
    cout << r << endl;
}

int main(){
    // Giúp nhập nhanh hơn
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while (t--)
    {
        input();
        solve();
    }
    
    return 0;
}