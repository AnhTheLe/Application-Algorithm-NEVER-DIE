#include<bits/stdc++.h>
// cho dãy số tự nhiên đc nhập từ bàn phím gồm N phần tử, liệt kê tất cả các dãy con gồm M phân từ thuộc dãy N
using namespace std;
const int MAX = 100;
int a[MAX];
int s[MAX];
int m,n;
void solution(){
    for (int i = 1; i<=m ; i++) cout<< s[a[i]]<<" ";
    cout << endl;
}

void Try(int k){
    if(k > m) solution();
    for (int i = a[k-1] + 1; i <= m+n-k; i++){
        a[k] = i;
        Try(k+1);
    }
}

int main(){
    a[0] = 0;
    s[0] = 0;
    cout << "N = ";
    cin >> n;
    cout<< "M = ";
    cin >> m;
    for (int i = 1; i<=n ; i++) cin >> s[i];
    Try(1);
    return 0;
}