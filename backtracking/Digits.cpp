#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, check[MAX];
int a[9] = {2, 10, 100, 1000, -100, 10, 100}, ans = 0;

void ql(int k, int s) {
    if(k == 7) {
        if(s == n + 62) ans++;
        return;
    }

    for(int i = 1; i <= 9; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            ql(k + 1, s + i * a[k]);
            check[i] = 0;
        }
    }
}

int main(){
    cin >> n;
    ql(0, 0);
    cout << ans;
}